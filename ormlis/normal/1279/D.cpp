#include <bits/stdc++.h>
#include <unordered_set>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

ll mod = 998244353;
ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) {
        return binpow(a, b - 1) * a % mod;
    }
    ll m = binpow(a, b / 2);
    return m * m % mod;
}

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> a(n);
    vector<pair<ll, ll>> b(1000001);
    ll inv = binpow(n, mod - 2);
    range(i, n) {
        int k; cin >> k;
        a[i].resize(k);
        ll invk = binpow(k, mod - 2);
        range(j, k) {
            cin >> a[i][j];
            b[a[i][j]].first = (b[a[i][j]].first + (inv * invk % mod)) % mod;
            b[a[i][j]].second++;
        }
    }
    ll ans = 0;
    for (auto p: b) {
        if (p.second) {
            ans = (ans + p.first * p.second % mod * inv % mod) % mod;
        }
    }
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests;
    tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}