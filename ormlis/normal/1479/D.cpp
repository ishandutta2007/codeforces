#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 3e5 + 1000;
const int md = 1e9 + 123;
const int md2 = 1e9 + 7;


int a[maxN];
int tin[maxN], tout[maxN];
int up[maxN][20];
int h[maxN];
vector<int> order;

vector<int> g[maxN];

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i < 20; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    tin[v] = order.size();
    order.push_back(a[v]);
    for (auto &u : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
    }
    tout[v] = order.size();
    order.push_back(a[v]);
}

int lca(int u, int v) {
    if (h[u] > h[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (h[up[v][i]] >= h[u]) v = up[v][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (up[v][i] != up[u][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

const int K = 600;

int cnt[maxN];
int c[maxN];

void add(int col) {
    c[col] ^= 1;
    if (c[col]) cnt[col / K]++;
    else cnt[col / K]--;
}

int have(int l, int r) {
    if (r - l <= K) {
        for (int i = l; i <= r; ++i) if (c[i]) return i;
        return -1;
    }
    int l1 = l / K;
    int r1 = r / K;
    for (int i = l1 + 1; i < r1; ++i)
        if (cnt[i]) {
            for (int j = i * K; j < (i + 1) * K; ++j) if (c[j]) return j;
        }
    l1++;
    l1 *= K;
    r1 *= K;
    for (int i = l; i < l1; ++i) if (c[i]) return i;
    for (int i = r1; i <= r; ++i) if (c[i]) return i;
    return -1;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    range(_, n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 1);
    vector<ar<int, 6>> qs(q);
    vector<int> ans(q);
    range(i, q) {
        qs[i][5] = i;
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        qs[i][2] = l;
        qs[i][3] = r;
        if (h[u] > h[v]) swap(u, v);
        int w = lca(u, v);
        if (w == u) {
            qs[i][0] = tout[v];
            qs[i][1] = tout[u];
            qs[i][4] = 0;
            continue;
        }
        if (tin[v] < tin[u]) swap(u, v);
        qs[i][0] = tout[u];
        qs[i][1] = tin[v];
        qs[i][4] = a[w];
    }
    sort(all(qs), [&](const ar<int, 6> &x, const ar<int, 6> &y) {
        return make_pair(x[0] / K, x[1]) < make_pair(y[0] / K, y[1]);
    });
    int L = 0, R = -1;

    for (auto &[l1, r1, lc, rc, C, i] : qs) {
        while (L > l1) add(order[--L]);
        while (R < r1) add(order[++R]);
        while (L < l1) add(order[L++]);
        while (R > r1) add(order[R--]);
        add(C);
        ans[i] = have(lc, rc);
        add(C);
    }
    range(i, q) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}