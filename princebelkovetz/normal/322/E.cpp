#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
const int N = 1e3 + 7, mod = 1e9 + 7;
vector <vector <int>> g;
vector <int> sz, lvl;
void getsz(int v, int p) {
    assert(!lvl[v]);
    sz[v] = 1;
    for (auto u : g[v]) {
        if (lvl[u] or u == p) continue;
        getsz(u, v);
        sz[v] += sz[u];
    }
}
int centroid(int v, int n, int p) {
    assert(!lvl[v]);
    for (auto u : g[v]) {
        if (lvl[u] or u == p) continue;
        if (sz[u] > n / 2)
            return centroid(u, n, v);
    }
    return v;
}
void cd(int v, int cur) {
    getsz(v, -1);
    int ct = centroid(v, sz[v], -1);
    lvl[ct] = cur;
    for (auto u : g[ct]) {
        if (lvl[u]) continue;
        cd(u, cur + 1);
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int n; cin >> n;
    g.resize(n + 1);
    lvl.resize(n + 1), sz.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cd(1, 1);
    for (int i = 1; i <= n; ++i) {
        cout << char('A' + lvl[i] - 1) << ' ';
    }
    cout << '\n';
    return 0;
}