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
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN];
int l[maxN], r[maxN];
ll dp[maxN][2];

void dfs(int v, int p) {
    dp[v][0] = dp[v][1] = 0;
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v][0] += max(abs(l[v] - l[u]) + dp[u][0], abs(l[v] - r[u]) + dp[u][1]);
        dp[v][1] += max(abs(r[v] - l[u]) + dp[u][0], abs(r[v] - r[u]) + dp[u][1]);
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
    for(int i = 1; i <= n; ++i) g[i].clear();
    range(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
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