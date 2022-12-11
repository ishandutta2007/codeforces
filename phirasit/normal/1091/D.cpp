#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353LL;

long long pow(long long a, long long b) {
    if (!b) return 1LL;
    if (b & 1LL) return a * pow(a, b-1) % mod;
    long long r = pow(a, b >> 1);
    r = (r * r) % mod;
    return r;
}

long long inv(long long x) { return pow(x, mod-2ll); }

const int N = 1e6 + 10;

long long fac[N];

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    fac[0] = 1LL;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (i * fac[i-1]) % mod;
    }

    long long ans = fac[n];
    for (int i = 1; i < n; ++i) {
        long long val = fac[n];
        val = (val * inv(fac[i])) % mod;
        val = (val * (fac[i] - 1)) % mod;
        ans = (ans + val) % mod;
    }

    ans = (ans % mod + mod) % mod;

    cout << ans << endl;

    return 0;
}