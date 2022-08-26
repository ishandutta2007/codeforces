//
// Created by Ormlis (t.me/averageCFenjoyer) on 20.03.2022.
//

#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef long double ld;

using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int C = 400;
const int B = 300;
const int maxN = 2e5 + 10;

struct fenwick {
    vl fenw;
    vi qq;
    int n;

    void build(int k) {
        n = k;
        fenw.resize(n, -INF);
    }

    void upd(int i, ll x) {
        qq.push_back(i);
        for (; i < n; i = i | (i + 1)) fenw[i] = max(fenw[i], x);
    }

    ll get(int i) {
        ll res = -INF;
        for (; i >= 0; i = ((i + 1) & i) - 1) res = max(res, fenw[i]);
        return res;
    }

    void clear() {
        for (auto &i : qq) {
            for (; i < n; i = i | (i + 1)) fenw[i] = -INF;
        }
        qq.clear();
    }
};

vi g[maxN];
int h[maxN];
bool used[maxN];
bool good[maxN];
ll ans[maxN];
int sz[maxN];

void dfs_sz(int v, int p) {
    sz[v] = 1;
    for (auto &u : g[v]) {
        if (u == p || used[u]) continue;
        dfs_sz(u, v);
        sz[v] += sz[u];
    }
}

int centroid(int v, int p, int n) {
    for (auto &u : g[v]) {
        if (used[u] || u == p) continue;
        if (sz[u] * 2 >= n) return centroid(u, v, n);
    }
    return v;
}

fenwick f[2];

void add(int bal1, int bal2, int len) {
    // bal1 + was >= 0
    // bal1 >= -was
    // -bal1 <= was
    // was >= 0
    assert(bal1 <= 0);
    bal1 = -bal1;
    if (bal2 % 2 == 0) {
        f[0].upd(bal1, len + bal2);
    } else {
        f[1].upd(bal1, len + bal2);
    }
}


void dfs2(int v, int p, int bal1, int bal2, int len) {
    if (good[v]) {
        add(bal1, bal2, len + h[v]);
    }
    for (auto &u : g[v]) {
        if (h[u] > h[v] || used[u] || u == p) continue;
        int bal = bal2;
        if (h[u] == h[v]) bal--;
        else bal++;
        dfs2(u, v, min(bal1, bal), bal, len + 1);
    }
}

void check(int v, int was, int len) {
    assert(was >= 0);
    ll val1 = f[0].get(was);
    if (val1 != -INF) {
        val1 += len;
        val1 += was;
        if (was % 2 == 1) val1--;
    }
    ll val2 = f[1].get(was);
    if (val2 != -INF) {
        val2 += len;
        val2 += was;
        if (was % 2 == 0) val2--;
    }
    ll val = max(val1, val2);
    if (val != -INF) {
        ans[v] = max(ans[v], val);
    }
}

void dfs1(int v, int p, int bal, int mn, int len) {
    mn = min(mn, bal);
    {
        if (mn == bal) {
            int was = -bal;
            check(v, was, len);
        }
    }
    for (auto &u : g[v]) {
        if (used[u] || u == p || h[u] < h[v]) continue;
        int bal2 = bal;
        if (h[u] == h[v]) bal2++;
        else bal2--;
        dfs1(u, v, bal2, mn, len + 1);
    }
}

void solve_centroid(int v) {
    dfs2(v, -1, 0, 0, 0);
    dfs1(v, -1, 0, 0, 0);
    f[0].clear();
    f[1].clear();
    dfs_sz(v, -1);
    used[v] = true;
    for (auto &u : g[v]) {
        if (used[u]) continue;
        solve_centroid(centroid(u, v, sz[u]));
    }
}

void solve() {
    int n;
    cin >> n;
    vi b(n);
    rep(i, n) cin >> b[i];
    rep(_, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    f[0].build(n + 5);
    f[1].build(n + 5);
    queue<int> q;
    rep(i, n) if (b[i]) {
            q.push(i);
        }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &u : g[v]) {
            if (b[u]) continue;
            b[u] = 1;
            h[u] = h[v] + 1;
            q.push(u);
        }
    }
    rep(i, n) {
        for (auto &j : g[i]) {
            if (h[i] == h[j]) good[i] = true;
        }
    }
    rep(i, n) ans[i] = max(ans[i], 1ll * h[i]);
    dfs_sz(0, -1);
    solve_centroid(centroid(0, -1, n));
    rep(i, n) cout << ans[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}