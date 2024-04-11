#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        ll x, y, p, q;
        scanf("%lld %lld %lld %lld", &x, &y, &p, &q);
        if (p == 1 && q == 1) {
            if (x == y) puts("0");
            else puts("-1");
            continue;
        }
        if (p == 0) {
            if (x == 0) puts("0");
            else puts("-1");
            continue;
        }
        ll mb = max(0ll, (q * x - y * p + p - 1)) / p;
        mb = max(mb, max(0ll, y * p - q * x) / (q - p));
        q /= __gcd(q, p);
        printf("%lld\n", (y + mb + q - 1) / q * q - y);
    }
    return 0;
}