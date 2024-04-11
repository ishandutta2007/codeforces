#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int X, Y, Z, T1, T2, T3;
    cin >> X >> Y >> Z >> T1 >> T2 >> T3;
    int stairs = abs(X - Y) * T1;
    int elevator = (abs(X - Z) + abs(X - Y)) * T2 + 3 * T3;
    cout << (stairs < elevator ? "NO" : "YES") << '\n';
}