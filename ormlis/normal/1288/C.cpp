

#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 1000000007;

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) return binpow(a, b - 1) * a % md;
    ll m = binpow(a, b / 2);
    return m * m % md;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> dp(m * 2 + 1, vector<ll> (n + 1));
    for(ll i = 0; i <= n; ++i) {
        dp[0][i] = 1;
    }
    for(ll l = 1; l <= m * 2; ++l) {
        for(ll f = 1; f <= n; ++f) {
            dp[l][f] = (dp[l][f - 1] + dp[l - 1][f]) % md;
        }
    }
    cout << dp[m * 2][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}