#include <cstdio>

typedef long long LL;

int n;
LL x, y;

int gcd(int x, int y) {
    return (y == 0) ? x : gcd(y, x%y);
}

int main () {
    scanf("%d %I64d %I64d", &n, &x, &y);
    int fpb = gcd(x, y);
    x /= fpb;
    y /= fpb;

    int a;
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        a %= (x + y);
        if (a == 0 || a == x + y - 1) puts("Both");
        else {
            LL l = 0;
            LL r = x * y;

            while (l < r) {
                LL k = l + r >> 1;
                if (k / x + k / y < a) l = k + 1;
                else r = k;
            }

            if (l % x == 0) puts("Vova");
            else puts("Vanya");
        }
    }

    return 0;
}