#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int v;
        cin >> v;
        v--;
        g[v].push_back(i);
        g[i].push_back(v);
    }
    vector<int> a(n);
    vector<ll> add(n);
    for (int i = 1; i < n; ++i) cin >> a[i];
    vector<vector<int>> verts(n);
    vector<int> pr(n);
    function<void(int, int, int)> dfs = [&](int v, int p, int h) {
        pr[v] = p;
        verts[h].push_back(v);
        for (auto &u : g[v]) {
            if (u == p) continue;
            dfs(u, v, h + 1);
        }
    };
    dfs(0, 0, 0);
    while (verts.back().empty()) verts.pop_back();
    int d = verts.size();
    for (int i = d - 1; i >= 1; --i) {
        ll mx = -INF, mn = INF;
        ll mx1 = -INF, mn1 = INF;
        for (auto &v : verts[i]) {
            mx = max(mx, a[v] + add[v]);
            mn = min(mn, a[v] - add[v]);
            mx1 = max(mx1, 1ll * a[v]);
            mn1 = min(mn1, 1ll * a[v]);
        }
        for (auto &v : verts[i]) {
            ll t = max(mx - a[v], a[v] - mn);
            t = max(t, add[v] + max(mx1 - a[v], a[v] - mn1));
            add[pr[v]] = max(add[pr[v]], t);
        }
    }
    cout << add[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}