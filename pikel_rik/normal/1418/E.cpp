#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const int inf = INT_MAX;
const int N = 2e5 + 5;

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

ll fact[N];
ll choose(int n, int k) {
    ll num = fact[n];
    ll dem = fact[k] * fact[n - k] % mod;
    return num * modinv(dem) % mod;
}

int n, m, d[N], a[N], b[N];
ll pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = i * fact[i - 1] % mod;

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];

    sort(d, d + n);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + d[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int idx = lower_bound(d, d + n, b[i]) - d;
        int c = n - idx;

        if (c < a[i]) {
            cout << "0\n";
        } else {
            ll ans = (pref[n] - pref[idx]) % mod * (c - a[i]) % mod * modinv(c) % mod;
            ans = (ans + pref[idx] % mod * (c + 1 - a[i]) % mod * modinv(c + 1)) % mod;
            cout << ans << '\n';
        }
    }
    return 0;
}