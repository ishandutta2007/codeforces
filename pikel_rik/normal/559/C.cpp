#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;
const int M = 2000 + 5;

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

ll fact[2*N];
ll choose(int n, int k) {
    ll num = fact[n];
    ll dem = fact[k] * fact[n - k] % mod;
    return num * modinv(dem) % mod;
}

int h, w, n;
pair<int, int> a[M];
ll dp[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen("input.txt", "r", stdin);

    fact[0] = 1;
    for (int i = 1; i < 2*N; i++) fact[i] = fact[i - 1] * i % mod;

    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(a, a + n);

    ll ans = choose(h + w - 2, h - 1);
    for (int i = 0; i < n; i++) {
        dp[i] = choose(a[i].first + a[i].second - 2, a[i].first - 1);
        for (int j = i - 1; j >= 0; j--) {
            if (a[j].first <= a[i].first and a[j].second <= a[i].second) {
                ll temp = choose(a[i].first + a[i].second - a[j].first - a[j].second, a[i].first - a[j].first);
                dp[i] = (dp[i] + mod - temp * dp[j] % mod) % mod;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ll temp = choose(h - a[i].first + w - a[i].second, h - a[i].first);
        ans = (ans + mod - temp * dp[i] % mod) % mod;
    }

    cout << ans << '\n';
    return 0;
}