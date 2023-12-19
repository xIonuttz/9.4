#include <iostream>
#include <vector>

// Base Shape class with pure virtual method computeArea
class Shape {
public:
    virtual double computeArea() const = 0;
    virtual ~Shape() {}
};

// Derived Circle class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double computeArea() const override {
        return 3.14159 * radius * radius; // Assuming pi is 3.14159
    }
};

// Derived Square class
class Square : public Shape {
private:
    double side;

public:
    Square(double side) : side(side) {}

    double computeArea() const override {
        return side * side;
    }
};

// Derived Triangle class
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double base, double height) : base(base), height(height) {}

    double computeArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    // Create a vector of shapes
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Square(3.0));
    shapes.push_back(new Triangle(4.0, 6.0));

    // Compute the sum of areas
    double totalArea = 0.0;
    for (const auto& shape : shapes) {
        totalArea += shape->computeArea();
    }

    // Display the total area
    std::cout << "Total Area: " << totalArea << " square units\n";

    // Cleanup dynamic objects
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}
