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
const int maxN = 1000 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN];
int sz[maxN];

void dfs(int v, int p) {
    sz[v] = 1;
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
    }
}

int nxt, step;

vector<ar<int, 3>> ans;
void dfs2(int v, int p, int cur) {
    ans.push_back({v, p, nxt - cur});
    cur = nxt;
    nxt += step;
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs2(u, v, cur);
    }
}

void solve() {
    int n;
    cin >> n;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int need = (n * n * 2) / 9;
    for (int v = 1; v <= n; ++v) {
        dfs(v, -1);
        int w = (int) g[v].size();
        vector<vector<int>> dp(w + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        range(i, w) {
            int u = g[v][i];
            dp[i + 1] = dp[i];
            for (int e = n; e >= sz[u]; --e) {
                if (dp[i][e - sz[u]]) dp[i + 1][e] = 1;
            }
        }
        int f = -1;
        for(int k = 0; k <= n; ++k) {
            if (!dp[w][k]) continue;
            int res = k + (k + 1) * (n - k - 1);
            if (res >= need) {
                f = k;
                break;
            }
        }
        if (f == -1) continue;
        vector<int> a;
        vector<int> b;
        int cur = f;
        for(int i = w - 1; i >= 0; --i) {
            if (dp[i][cur]) {
                b.push_back(g[v][i]);
            } else {
                assert(cur >= sz[g[v][i]]);
                assert(dp[i][cur - sz[g[v][i]]]);
                a.push_back(g[v][i]);
                cur -= sz[g[v][i]];
            }
        }
        nxt = 1;
        step = 1;
        for(auto &u : a) {
            dfs2(u, v, 0);
        }
        assert(nxt == f + 1);
        nxt = step = f + 1;
        for(auto &u : b) {
            dfs2(u, v, 0);
        }
        for(auto &[u, v, x] : ans) {
            cout << u << ' ' << v << ' ' << x << '\n';
        }
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}