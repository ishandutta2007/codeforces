#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    range(i, m) {
        int x, y; cin >> x >> y;
        if (x == y) continue;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> was(n + 1);
    int ans = 0;
    function<void(int, int)> dfs = [&] (int v, int p) {
        ans++;
        was[v] = 1;
        bool f = false;
        for(auto &u : g[v]) {
            if (u == p && !f) {
                f = true;
                continue;
            }
            if (was[u] == 1) {
                ans += 2;
                continue;
            } else if (was[u] == 2) continue;
            dfs(u, v);
        }
        was[v] = 2;
    };
    for(int i = 1; i <= n; ++i) {
        if (was[i] || g[i].empty()) continue;
        dfs(i, i);
        ans--;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}