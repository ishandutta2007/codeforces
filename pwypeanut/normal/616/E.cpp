#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long a, b;

int main() {
    cin >> a >> b;
    long long ans = 0;
    if (b > a) {
        ans += (((b - a) % MOD) * (a % MOD)) % MOD;
        ans %= MOD;
        b = a;
    }
    for (int i = 1; i <= min(b, (long long)sqrt(a)); i++) {
        ans += a % i;
        ans %= MOD;
    }
    if (b <= sqrt(a)) {
        printf("%lld\n", ans);
        return 0;
    }
    for (int i = a/b; i < ceil(sqrt(a)); i++) {
            long long hi = a/i, lo = a/(i+1);
            if (hi <= 10000000 && hi*hi <= a) break;
            if (i == a/b) hi = b;
            long long cur = hi - lo;
            cur %= MOD;
            cur *= a % MOD;
            cur %= MOD;
            long long cur2 = i;
            cur2 *= (hi - lo) % MOD;
            cur2 %= MOD;
            cur2 *= (hi + lo + 1) % MOD;
            cur2 %= MOD;
            cur2 *= 500000004;
            cur2 %= MOD;
            ans += cur - cur2;
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
            //printf("%lld\n", ans);
        }
        printf("%lld\n", ans);
}