#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << (A == D && (A > 0 || C == 0) ? 1 : 0) << '\n';
}