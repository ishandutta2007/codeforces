#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

i64 K, N, ans = 1;

int main() {
    scanf("%lld%lld", &N, &K);
    i64 l = 1, r;
    while (l << 1 <= N) {
        l <<= 1;
    }
    r = l + l - 1;

    i64 a = 1;
    i64 b = 0;
    for (i64 x = N; x >= 1; ) {
        // printf("x=%lld, a=%lld, b=%lld, l=%lld,r=%lld\n", x, a, b, l, r);
        if (x % 2 == 0) {
            if (b >= K) {
                ans = max(ans, r);
            }
            if (a + b >= K) {
                ans = max(ans, x);
            }
            if (x - 1 >= l && b + b + 1 >= K) {
                ans = max(ans, x - 1);
            }
            if (x - 2 >= l && b * 4 + 2 >= K) {
                ans = max(ans, x - 2);
            }
            a = a + b + 1;
        } else {
            if (b >= K) {
                ans = max(ans, r);
            }
            if (a >= K) {
                ans = max(ans, x);
            }
            if (b + b + 1 + a >= K) {
                ans = max(ans, x - 1);
            }
            if (x - 3 >= l && b * 4 + 2 >= K) {
                ans = max(ans, x - 3);
            }
            a = a + b + b + 2;
        }
        x >>= 1;
        l >>= 1;
        r >>= 1;
        b = b + b + 1;
    }
    printf("%lld\n", ans);
    return 0;
}