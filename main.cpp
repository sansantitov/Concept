#include <iostream>
#include<string>
#include <concepts>
//=========================================================================================================================================
template<typename T>
concept ComplexConcept = requires(const T v ) {
    {v.hash()}->std::convertible_to<long>;
    {v.toString()}->std::same_as<std::string>;
    
} && !std::has_virtual_destructor_v<T>;

class TestObject {
public:
    TestObject() = default;
    TestObject(int16_t v) :num(v) {};
    //~TestObject() = default;
    virtual ~TestObject() {};
    int16_t hash() const { return 34; };
    std::string toString() const { return std::to_string(num); }
private:
    int16_t num{ 0 };
    
};

void PrintObject(ComplexConcept auto &t) { std::cout << t.toString() <<" "<<t.hash() << std::endl; };


//==========================================================================================================================================
int main() {
    TestObject x{ 42 };
    PrintObject(x);
    return 0;

}