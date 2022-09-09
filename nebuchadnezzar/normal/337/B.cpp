#include <cstdio>
#include <iostream>

using namespace std;

int a, b, c, d, x, y;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int x, y;
    cin >> a >> b >> c >> d;
    if (a * d == c * b) {
        x = 0;
        y = 1;
    } else if (a * d > c * b) {
        x = a * d - c * b;
        y = a * d;
        int z = gcd(x, y);
        x /= z;
        y /= z;
    } else {
        x = b * c - d * a;
        y = b * c;
        int z = gcd(x, y);
        x /= z;
        y /= z;
    }

    cout << x << "/" << y;

    return 0;
}