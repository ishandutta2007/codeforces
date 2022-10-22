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
#include <unordered_map>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, N = 200;

vector <vector <int>> g, binup;
vector <int> h, tin, tout, sz, par, d;
vector <bool> used;

int lg = 0, timer = 1;

void dfs(int v, int p = 1) {

    binup[0][v] = p;
    for (int i = 1; i < lg; ++i)
        binup[i][v] = binup[i - 1][binup[i - 1][v]];

    tin[v] = timer++;
    for (auto u : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
    }
    tout[v] = timer++;

}

bool isAnc(int v, int u) {
    return tin[v] <= tin[u] and tout[u] <= tout[v];
}

int lca(int u, int v) {
    if (isAnc(u, v)) return u;
    if (isAnc(v, u)) return v;
    for (int i = lg - 1; i >= 0; --i) {
        if (!isAnc(binup[i][v], u))
            v = binup[i][v];
    }
    return binup[0][v];
}

int dist(int u, int v) {
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

void get_sz(int v, int p) {
    sz[v] = 1;
    for (auto u : g[v]) {
        if (used[u] or u == p) continue;
        get_sz(u, v);
        sz[v] += sz[u];
    }
}

int find(int v, int p, int n) {
    for (auto u : g[v]) {
        if (used[u] or u == p) continue;
        if (sz[u] > n / 2)
            return find(u, v, n);
    }
    return v;
}

int build(int v, int pr) {
    get_sz(v, pr);
    v = find(v, pr, sz[v]);
    used[v] = true;
    for (auto u : g[v]) {
        if (used[u]) continue;
        par[build(u, v)] = v;
    }
    return v;
}

void turnOn(int v, int u) {
    d[v] = min(d[v], dist(v, u));
    if (!par[v]) return;
    turnOn(par[v], u);
}

int query(int v, int u) {
    if (!par[v]) return dist(v, u) + d[v];
    return min(query(par[v], u), dist(v, u) + d[v]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int n, m; cin >> n >> m;
    while ((1 << lg) < n) lg++;
    lg++;

    g.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    h.resize(n + 1);
    used.resize(n + 1);
    d.resize(n + 1, mod);
    sz.resize(n + 1);
    par.resize(n + 1);
    binup.resize(lg, vector <int>(n + 1));

    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    build(1, 1);
    turnOn(1, 1);

    while(m --> 0) {
        int t, v; cin >> t >> v;
        if (t == 1) {
            turnOn(v, v);
        }
        else {
            cout << query(v, v) << '\n';
        }
    }


    return 0;
}