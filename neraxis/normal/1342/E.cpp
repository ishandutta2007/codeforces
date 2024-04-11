#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int MOD = 998244353;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return res;
}

int inv(int x) {
    return power(x, MOD - 2);
}

const int N = 200005;

int fac[N], ifac[N];

void init_combi() {
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = inv(fac[i]); 
    }
}

int C(int n, int k) {
    return 1LL * ifac[k] * ifac[n - k] % MOD * fac[n] % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    init_combi();
    long long n, k;
    cin >> n >> k;
    if (k == 0) return cout << fac[n], 0;
    if (k > n - 1) return cout << 0, 0;
    int t = n - k;
    long long ans = 0;
    int sign = 1;
    for (int i = 0; i < t; i++) {
        ans = ans + 1LL * C(t, i) * sign * power(t - i, n) % MOD * ifac[n] % MOD;
        ans %= MOD;
        if (ans < 0) ans += MOD;
        sign = -sign;
    }
    // cout << ans << endl;
    ans = 2LL * C(n, t) * fac[n] % MOD * ans % MOD;
    cout << ans;
    return 0;
}