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
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 998244353;

vector<int> g[maxN];
int w[maxN];
bool have_up[maxN];
bool was[maxN];

ll dfs3(int v, int p) {
    ll res = w[v];
    for (auto &u : g[v]) {
        if (have_up[u] || u == p) continue;
        res = max(res, w[v] + dfs3(u, v));
    }
    return res;
}

ll add = 0;
ll ans = 0;

void dfs(int v, int p) {
    was[v] = true;
    for (auto &u : g[v]) {
        if (u == p) continue;
        if (was[u]) {
            have_up[v] = true;
            continue;
        }
        dfs(u, v);
        if (have_up[u]) have_up[v] = true;
    }
}

void dfs2(int v) {
    was[v] = true;
    ans += w[v];
    for(auto &u : g[v]) {
        if (was[u]) continue;
        if (have_up[u]) {
            dfs2(u);
            continue;
        }
        add = max(add, dfs3(u, v));
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    range(_, m) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int s;
    cin >> s;
    dfs(s, -1);
    for(int i = 1; i <= n; ++i) was[i] = false;
    dfs2(s);
    cout << ans + add << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}