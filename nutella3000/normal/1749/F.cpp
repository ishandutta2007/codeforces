#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9;
const int N = 1 << 18, K = 21;
int n, m;
vector<int> g[N];
int pr[N][K], sz[N], tin[N], tout[N], top[N], T = 0;
int lazy[2*N][K];

void predfs(int v, int pr = -1) {
    sz[v] = 1;
    for (int i = 0; i < size(g[v]); ++i) {
        int to = g[v][i];
        if (to == pr) continue;
        predfs(to, v);
        sz[v] += sz[to];
        if (g[v][0] == pr || sz[to] > sz[g[v][0]]) swap(g[v][i], g[v][0]);
    }
}

void dfs(int v) {
    tin[v] = T++;

    for (int to : g[v]) {
        if (sz[to] > sz[v]) continue;
        if (sz[to] * 2 < sz[v]) top[to] = to;
        else top[to] = top[v];

        pr[to][0] = v;
        for (int i = 1; i < K; ++i) {
            pr[to][i] = pr[pr[to][i-1]][i-1];
        }
        dfs(to);
    }
    tout[v] = T;
}

bool ispar(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

pair<int, int> get_lca(int u, int v) {
    for (int i = K-1; i >= 0; --i) {
        if (!ispar(pr[u][i], v)) u = pr[u][i];
        if (!ispar(pr[v][i], u)) v = pr[v][i];
    }
    return {u, v};
}

void st_add(int u, int d, int k) {
    lazy[N + tin[u]][d] += k;
}
void st_add(int l, int r, int d, int k) {
    if (d < 0) return;
    for (l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) lazy[l++][d] += k;
        if (r & 1) lazy[--r][d] += k;
    }
}

void add_path(int u, int l, int d, int k) {
    while (ispar(l, top[u])) {
        int v = top[u];
        st_add(tin[v], tin[u], d, k);
        u = pr[v][0];
        if (v == 0) return;
    }
    st_add(tin[l], tin[u], d, k);
}

void Set(int u, int v, int k, int d) {
    auto [ul, vl] = get_lca(u, v);
    int l = ispar(ul, v) ? ul : pr[ul][0];

    // cout << "Set " << l+1 << endl;
    for (int rem = d, q = l; rem > 0 && q != 0; --rem, q = pr[q][0]) {
        st_add(pr[q][0], rem-1, k);
        if (rem >= 2) st_add(q, rem-2, -k);
    }
    st_add(l, d, -k);

    add_path(u, l, d, k);
    if (ul != l) add_path(u, ul, d-1, -k);

    add_path(v, l, d, k);
    if (vl != l) add_path(v, vl, d-1, -k);
}

vector<int> st_get(int u) {
    vector<int> d(K);
    for (int a = tin[u] + N; a; a >>= 1) {
        for (int i = 0; i < K; ++i) {
            d[i] += lazy[a][i];
        }
    }
    return d;
}

int Get(int u) {
    int res = 0;
    for (int d = 0; d <= 20; ++d, u = pr[u][0]) {
        auto t = st_get(u);
        for (int i = d; i < t.size(); ++i) {
            res += t[i];
        }
        if (u == 0) break;
    }
    return res;
}

void run() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    predfs(0);
    dfs(0);

    cin >> m;
    while (m--) {
        int t; cin >> t;
        // cout << "problem " << endl;
        if (t == 1) {
            int v; cin >> v; --v;
            cout << Get(v) << '\n';
        } else {
            int u, v, k, d; cin >> u >> v >> k >> d; --u, --v;
            Set(u, v, k, d);
        }
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        run();
    }
}