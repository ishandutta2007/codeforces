#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool solvable(int ax, int ay, int bx, int by, int cx, int cy) {
    if (cx < ax ^ bx < ax)
        return false;

    if (cy < ay ^ by < ay)
        return false;

    return true;
}

int main() {
    int n, ax, ay, bx, by, cx, cy;
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    cout << (solvable(ax, ay, bx, by, cx, cy) ? "YES" : "NO") << '\n';
}