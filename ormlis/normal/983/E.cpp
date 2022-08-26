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

struct merge_sort_tree {
    struct Node {
        vector<ar<int, 3>> val{};

        void combine(const Node &a, const Node &b) {
            val.clear();
            int i = 0, j = 0;
            while (i < (int) a.val.size() || j < (int) b.val.size()) {
                val.push_back({-1, i, j});
                if (i == (int) a.val.size()) {
                    val.back()[0] = b.val[j][0];
                    j++;
                } else if (j == (int) b.val.size() || a.val[i][0] < b.val[j][0]) {
                    val.back()[0] = a.val[i][0];
                    i++;
                } else {
                    val.back()[0] = b.val[j][0];
                    j++;
                }
            }
        }
    };

    vector<Node> tree{};
    int n{};

    void build(int k, vector<int> &a) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n, a);
    }

    void make(int v, int l, int r, vector<int> &a) {
        if (l + 1 == r) {
            tree[v].val = {{a[l], 0, 0}};
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make((v << 1) + 1, (l + r) >> 1, r, a);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    int get(int v, int l, int r, int &lq, int &rq, int &i) {
        if (l >= rq || r <= lq || i == tree[v].val.size()) return INFi;
        if (lq <= l && r <= rq) {
            return tree[v].val[i][0];
        }
        return min(get(v << 1, l, (l + r) >> 1, lq, rq, tree[v].val[i][1]),
                   get((v << 1) + 1, (l + r) >> 1, r, lq, rq, tree[v].val[i][2]));
    }

    int get(int lq, int rq, int l) {
        ar<int, 3> for_find = {l, -1, -1};
        int j = lower_bound(all(tree[1].val), for_find) - tree[1].val.begin();
        return get(1, 0, n, lq, rq, j);
    }
};

const ll INF = 2e18;
const int maxN = 2e5 + 5;
const int LG = 20;

vi g[maxN];
int up[maxN][LG];
int h[maxN];
int jump[maxN][LG];
int tin[maxN];
int tout[maxN];
int T = 0;

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 0; i < 20; ++i) jump[v][i] = v;
    for (int i = 1; i < 20; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    tin[v] = T++;
    for (auto &u : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
    }
    tout[v] = T;
}

void dfs2(int v) {
    for (auto &u : g[v]) {
        dfs2(u);
        if (h[jump[u][0]] < h[jump[v][0]]) {
            jump[v][0] = jump[u][0];
        }
    }
}

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


void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    dfs(1, 1);
    int m;
    cin >> m;
    vector<pair<int, int>> paths;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        if (tin[a] > tin[b]) swap(a, b);
        paths.emplace_back(tin[a], tin[b]);
        int w = lca(a, b);
        if (h[w] < h[jump[a][0]]) {
            jump[a][0] = w;
        }
        if (h[w] < h[jump[b][0]]) {
            jump[b][0] = w;
        }
    }
    dfs2(1);
    sort(all(paths));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < LG; ++j) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
    merge_sort_tree mst;
    vector<int> vals;
    for (auto &[l, r] : paths) vals.push_back(r);
    mst.build(paths.size(), vals);
    int q;
    cin >> q;
    rep(_, q) {
        int v, u;
        cin >> v >> u;
        int w = lca(v, u);
        int ans = 0;
        for (int j = LG - 1; j >= 0; --j) {
            if (h[jump[v][j]] > h[w]) {
                v = jump[v][j];
                ans += (1 << j);
            }
            if (h[jump[u][j]] > h[w]) {
                u = jump[u][j];
                ans += (1 << j);
            }
        }
        if (h[jump[v][0]] > h[w] || h[jump[u][0]] > h[w]) {
            cout << "-1\n";
            continue;
        }
        if (v == u) {
            cout << ans << '\n';
            continue;
        }
        ans++;
        if (v == w || u == w) {
            cout << ans << '\n';
            continue;
        }
        if (tin[v] > tin[u]) swap(u, v);
        int L1 = tin[v];
        int R1 = tout[v];
        int L2 = tin[u];
        int R2 = tout[u];
        int lq = lower_bound(all(paths), pair<int, int>{L1, -1}) - paths.begin();
        int rq = lower_bound(all(paths), pair<int, int>{R1, -1}) - paths.begin();
        int to = mst.get(lq, rq, L2);
        if (to >= R2) {
            ans++;
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}