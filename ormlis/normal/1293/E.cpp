#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 3001;
ll md = 998244353;
int n;
ll s = 0;

unordered_set<int> g[maxN];
ll dp[maxN][maxN];
queue<pair<int, int>> q[maxN];
int c[maxN][maxN];

void dfs(int cc, int v, int p = -1) {
    c[cc][v] = 1;
    for(auto u: g[v]) {
        if (u == p) continue;
        dfs(cc, u, v);
        c[cc][v] += c[cc][u];
    }
}

void solve2(int v) {
    int siz = q[v].size();
    range(_, siz) {
        int u = q[v].front().first;
        int u2 = q[v].front().second;
        q[v].pop();
        for(auto x: g[u]) {
            if (dp[v][x] == -1) {
                dp[v][x] = max(dp[v][u], dp[u2][x]) + 1ll * c[v][x] * (c[v][v] - c[v][u2]);
                q[v].push({x, u2});
            }
        }
    }
}


void solve() {
    cin >> n;
    range(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    range(i, n) {
        range(j, n) {
            dp[i][j] = -1;
        }
    }
    range(i, n) {
        dfs(i, i);
        for(auto u: g[i]) {
            q[i].push({u, u});
            dp[i][i] = 0;
            dp[i][u] = 1ll * c[i][u] * (c[i][i] - c[i][u]);
        }
    }
    range(i, n) {
        range(j, n) solve2(j);
    }
    ll ans = 0;
    range(i, n) {
        range(j, n) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
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