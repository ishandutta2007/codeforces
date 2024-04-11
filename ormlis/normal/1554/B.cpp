#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 5e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k; cin >> n >> k;
    int t = 0;
    while((1 << t) <= n) t++;
    vector<pair<ll, ll>> dp(1 << t, {-INF, -INF});

    auto combine = [] (pair<ll, ll> a, pair<ll, ll> b) {
        pair<ll, ll> c = {max(a.first, b.first), -INF};
        for(auto t : {a.first, b.first, a.second, b.second}) {
            if (t == c.first) continue;
            c.second = max(c.second, t);
        }
        return c;
    };
    range(i, n) {
        int x; cin >> x;
        pair<ll, ll> cur = {i + 1, -INF};
        dp[x] = combine(dp[x], cur);
    }
    ll ans = -INF;
    range(mask, 1 << t) {
        range(j, t) {
            if (mask & (1 << j)) dp[mask] = combine(dp[mask], dp[mask ^ (1 << j)]);
        }
        if (dp[mask].second == -INF) continue;
        ans = max(ans, dp[mask].first * dp[mask].second - mask * k);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}