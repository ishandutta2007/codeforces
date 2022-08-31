#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;

vector<int> g[maxN];
vector<pair<int, int>> paths;
vector<pair<int, int>> bad_edges;

pair<int, bool> dfs(int v, int p) {
    int cnt = 2;
    int a = v;
    int b = v;
    for (auto &u : g[v]) {
        if (u == p) continue;
        auto[t, need] = dfs(u, v);
        if (cnt && need) {
            cnt--;
            if (a == v) {
                a = t;
            } else {
                b = t;
            }
            continue;
        }
        bad_edges.emplace_back(u, v);
        if (need) {
            paths.emplace_back(u, t);
        }
    }
    if (cnt) return {a, true};
    paths.emplace_back(a, b);
    return {-1, false};
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) g[i].clear();
    bad_edges.clear();
    paths.clear();
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    auto[t, need] = dfs(1, -1);
    if (need) {
        paths.emplace_back(1, need);
    }
    assert(paths.size() == bad_edges.size() + 1);
    cout << bad_edges.size() << '\n';
    range(i, (int) bad_edges.size()) {
        cout << bad_edges[i].first << ' ' << bad_edges[i].second << ' ' << paths[i].second << ' '
             << paths[i + 1].first << '\n';
    }
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