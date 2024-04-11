#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5 + 30;
const int LG = 20;

vi g[maxN];
int tin[maxN];
int tout[maxN];
int up[maxN][LG];
int h[maxN];
int T = 1;


int lca(int v, int u) {
    if (h[v] < h[u]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (h[up[v][i]] >= h[u]) v = up[v][i];
    }
    if (u == v) return v;
    for (int i = 19; i >= 0; --i) {
        if (up[v][i] != up[u][i]) v = up[v][i], u = up[u][i];
    }
    return up[v][0];
}

int dist(int a, int b) {
    return h[a] + h[b] - 2 * h[lca(a, b)];
}

void dfs(int v, int p) {
    tin[v] = T++;
    up[v][0] = p;
    for(int i = 1; i < LG; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    for(auto &u : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
    }
    tout[v] = T;
}

bool check(int p, int v) {
    return tin[p] <= tin[v] && tout[v] <= tout[p];
}

void solve() {
    int n; cin >> n;
    rep(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    T = 1;
    h[1] = 0;
    dfs(1, 1);
    int q; cin >> q;
    rep(_, q) {
        int k; cin >> k;
        vi p(k);
        rep(i, k) cin >> p[i];
        sort(all(p), [&] (const int &i, const int &j) {
            return tin[i] < tin[j];
        });
        int L = p[0];
        for(int i = 1; i < k; ++i) L = lca(L, p[i]);
        int R = L;
        int M = L;
        bool ok = true;
        for(auto &v : p) {
            if (check(L, v)) L = v;
            else if (check(R, v)) R = v;
            else ok = false;
        }
        ok &= (dist(L, R) == dist(L, M) + dist(M, R));
        if (!ok) cout << "NO\n";
        else cout << "YES\n";
    }
    for(int i = 1; i <= n; ++i) {
        g[i].clear();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}