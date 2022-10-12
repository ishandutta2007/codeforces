#include <bits/stdc++.h>
using namespace std;

int a, b, x, y;

int gcd (int x, int y) {
    return (y == 0) ? x : gcd(y, x % y);
}

int main () {
    scanf("%d %d %d %d", &a, &b, &x, &y);

    int fpb = gcd(x, y);

    x /= fpb;
    y /= fpb;

    int r = min(a / x, b / y);

    printf("%d %d\n", r * x, r * y);

    return 0;
}