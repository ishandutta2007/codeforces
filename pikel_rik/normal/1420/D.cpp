#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const int inf = INT_MAX;
const int N = 3e5 + 5;

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

int n, k, l[N], r[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = i * fact[i - 1] % mod;

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[l[i]].push_back(i + 1);
        mp[r[i]].push_back(-i - 1);
    }

    int cnt = 0;
    ll ans = 0;

    for (auto& [x, v] : mp) {
        sort(v.begin(), v.end(), greater<>());
        for (int i : v) {
            if (i < 0) {
                cnt--;
            } else {
                cnt++;
                if (cnt >= k) {
                    ans = (ans + choose(cnt - 1, k - 1)) % mod;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}