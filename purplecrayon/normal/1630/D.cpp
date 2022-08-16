#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;
const ll INF = 1e18+10;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& x : a) cin >> x;

    auto cost = [&](vector<int> b) {
        ar<ll, 2> dp{0, -INF};
        for (auto x : b) {
            ar<ll, 2> ndp;
            ndp[0] = max(dp[0] + x, dp[1] - x);
            ndp[1] = max(dp[1] + x, dp[0] - x);
            dp = ndp;
        }
        return dp;
    };

    int k = 0;
    while (m--) {
        int x; cin >> x;
        k = std::gcd(k, x);
    }
    vector<vector<int>> b(k);
    for (int i = 0; i < n; i++) b[i % k].push_back(a[i]);

    ar<ll, 2> ans; ans.fill(0);
    for (auto& c : b) {
        ar<ll, 2> cur = cost(c);
        ans[0] += cur[0], ans[1] += cur[1];
    }
    cout << max(ans[0], ans[1]) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}