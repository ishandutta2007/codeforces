#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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

const int maxN = 5e5 + 5;
int dsu[maxN];
int sets[maxN];
int mxs[maxN];
int maxe[maxN];
int e[maxN];
vpi g[maxN];
const int LG = 20;
int up[maxN][LG];
int mup[maxN][LG];
int h[maxN];

void dfs(int v, int p) {
    up[v][0] = p;
    for(int i = 1; i < LG; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
        mup[v][i] = max(mup[v][i - 1], mup[up[v][i - 1]][i - 1]);
    }
    for(auto &[u, w] : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        mup[u][0] = w;
        dfs(u, v);
    }
}

int dist(int a, int b) {
    if (a == -1 || b == -1) return -1;
    if (h[a] > h[b]) swap(a, b);
    int res = -1;
    for(int j = LG - 1; j >= 0; --j) {
        if (h[up[b][j]] >= h[a]) {
            res = max(res, mup[b][j]);
            b = up[b][j];
        }
    }
    if (a == b) return res;
    for(int j = LG - 1; j >= 0; --j) {
        if (up[a][j] != up[b][j]) {
            res = max(res, mup[a][j]);
            res = max(res, mup[b][j]);
            a = up[a][j];
            b = up[b][j];
        }
    }
    res = max(res, mup[a][0]);
    res = max(res, mup[b][0]);
    return res;
}

int get_value(int x) {
    int v = x;
    int result = max(mxs[x], dist(sets[x], v));
    while (dsu[x] != x) {
        x = dsu[x];
        if (sets[x] != -1) result = dist(sets[x], v);
        result = max(result, mxs[x]);
    }
    assert(result != -1);
    return result;
}

ar<int, 3> get_root(int x) {
    if (dsu[x] == x) return {x, -1, -1};
    auto [r, v1, v2] = get_root(dsu[x]);
    dsu[x] = r;
    if (v1 != -1) {
        sets[x] = v1;
        mxs[x] = v2;
        return {r, v1, v2};
    }
    v1 = sets[x];
    v2 = max(v2, mxs[x]);
    mxs[x] = v2;
    return {r, v1, v2};
}

int R = 2e5 + 100;

void unio(int a, int b, int w) {
    int ra = get_root(a)[0];
    int rb = get_root(b)[0];
    int nw = R++;
    dsu[nw] = nw;
    sets[nw] = -1;
    mxs[nw] = -1;
    if (maxe[ra] > maxe[rb]) {
        sets[rb] = b;
        mxs[rb] = max(get_value(a), w);
    } else if (maxe[rb] > maxe[ra]) {
        sets[ra] = a;
        mxs[ra] = max(get_value(b), w);
    } else {
        mxs[nw] = max({get_value(a), get_value(b), w});
    }
    dsu[ra] = nw;
    dsu[rb] = nw;
    maxe[nw] = max(maxe[ra], maxe[rb]);
}

void solve() {
    // set dist(A, v)
    // max= x
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> e[i];
    vector<ar<int, 4>> edges;
    rep(_, n - 1) {
        int a, b, c, t; cin >> a >> b >> c >> t;
        g[a].emplace_back(b, t);
        g[b].emplace_back(a, t);
        edges.push_back({c, a, b, t});
    }
    dfs(1, 1);
    for(int i = 1; i <= n; ++i) {
        dsu[i] = i;
        sets[i] = -1;
        mxs[i] = 0;
        maxe[i] = e[i];
    }
    vector<ar<int, 3>> qs;
    rep(i, q) {
        int v, x; cin >> v >> x;
        qs.push_back({v, x, i});
    }
    vi ans1(q), ans2(q);
    sort(rall(qs));
    sort(rall(edges));
    int t = 0;
    for(auto &[need, v, i] : qs) {
        while(t < n - 1 && edges[t][0] >= need) {
            unio(edges[t][1], edges[t][2], edges[t][3]);
            t++;
        }
        ans1[i] = maxe[get_root(v)[0]];
        ans2[i] = get_value(v);
    }
    rep(i, q) cout << ans1[i] << ' ' << ans2[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}