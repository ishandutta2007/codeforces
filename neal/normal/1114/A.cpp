#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int A, B, C;
    cin >> A >> B >> C;
    puts(A >= X && A + B >= X + Y && A + B + C >= X + Y + Z ? "YES" : "NO");
}