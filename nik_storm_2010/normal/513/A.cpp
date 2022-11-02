#include <iostream>

using namespace std;

int main() {
    int n1{}, n2{}, k1{}, k2{};
    cin >> n1 >> n2 >> k1 >> k2;
    cout << (n1 > n2 ? "First" : "Second") << "\n";
    return 0;
}