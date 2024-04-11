#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct segment_tree {
    struct Node {
        vector<int> s;
    };

    static void combine(Node &a, Node &b, Node &res) {
        res.s = {};
        int i = 0, j = 0;
        while (res.s.size() < 10 && (i < a.s.size() || j < b.s.size())) {
            if (i != a.s.size() && (j == b.s.size() || a.s[i] < b.s[j])) {
                res.s.push_back(a.s[i]);
                i++;
            } else if (j != b.s.size() && (i == a.s.size() || a.s[i] > b.s[j])) {
                res.s.push_back(b.s[j]);
                j++;
            } else {
                res.s.push_back(a.s[i]);
                i++;
                j++;
            }
        }
    }

    int n{};
    vector<Node> tree{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void upd(int v, int l, int r, int pos, vector<int> &x) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            tree[v].s = x;
            if (tree[v].s.size() > 10) tree[v].s.resize(10);
            return;
        }
        upd(v * 2, l, (l + r) / 2, pos, x);
        upd(v * 2 + 1, (l + r) / 2, r, pos, x);
        combine(tree[v * 2], tree[v * 2 + 1], tree[v]);
    }

    void upd(int pos, vector<int> x) {
        upd(1, 0, n, pos, x);
    }

    Node get(int lq, int rq, int v, int l, int r) {
        if (r <= lq || l >= rq) return {};
        if (lq <= l && r <= rq) {
            return tree[v];
        }
        Node a = get(lq, rq, v * 2, l, (l + r) / 2);
        Node b = get(lq, rq, v * 2 + 1, (l + r) / 2, r);
        Node res;
        combine(a, b, res);
        return res;
    }

    Node get(int lq, int rq) {
        return get(lq, rq, 1, 0, n);
    }
};

struct segment_tree2 {

    int n{};
    vector<int> tree{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void upd(int v, int l, int r, int pos, int x) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            tree[v] = x;
            return;
        }
        upd(v << 1, l, (l + r) >> 1, pos, x);
        upd((v << 1) + 1, (l + r) >> 1, r, pos, x);
        tree[v] = min(tree[v << 1], tree[(v << 1) + 1]);
    }

    int get(int lq, int rq, int v, int l, int r) {
        if (r <= lq || l >= rq) return INFi;
        if (lq <= l && r <= rq) {
            return tree[v];
        }
        int a = get(lq, rq, v << 1, l, (l + r) >> 1);
        int b = get(lq, rq, (v << 1) + 1, (l + r) >> 1, r);
        return min(a, b);
    }

    void upd(int pos, int x) {
        upd(1, 0, n, pos, x);
    }

    int get(int lq, int rq) {
        return get(lq, rq, 1, 0, n);
    }
};

segment_tree st1;
segment_tree2 st2;

vector<int> c[maxN];
vector<int> g[maxN];
int h[maxN], f[maxN];
vector<int> order;

void dfs_for_lca(int v, int p, int hcur) {
    f[v] = order.size();
    order.push_back(v);
    h[v] = hcur;
    for (auto u: g[v]) {
        if (u == p) continue;
        dfs_for_lca(u, v, hcur + 1);
        order.push_back(v);
    }
}

int get_lca(int v, int u) {
    if (u == v) return h[u];
    if (f[u] < f[v]) swap(u, v);
    auto w = st2.get(f[v], f[u] + 1);
    return w;
}

set<int> res[maxN];
int a[maxN];
vector<pair<int, int>> queries[maxN];

int current = 0;

void dfs(int v, int p) {
    st1.upd(current, c[v]);
    current++;
    for (auto &w: queries[v]) {
        int lc = get_lca(v, w.first);
        auto aw = st1.get(lc, current).s;
        for (auto &x: aw) res[w.second].insert(x);
    }
    for (auto u: g[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    current--;
    st1.upd(current, {});
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    range(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    range(i, m) {
        int ci;
        cin >> ci;
        c[ci].push_back(i + 1);
    }

    for (int i = 1; i <= n; ++i) {
        while (c[i].size() > 10) c[i].erase((--c[i].end()));
    }

    dfs_for_lca(1, -1, 0);

    // for lca
    st2.build(order.size());
    range(i, order.size()) st2.upd(i, h[order[i]]);

    st1.build(n);

    range(i, q) {
        int u, v;
        cin >> u >> v >> a[i];
        queries[u].emplace_back(v, i);
        queries[v].emplace_back(u, i);
    }

    dfs(1, -1);

    range(i, q) {
        int k = min(a[i], (int) res[i].size());
        cout << k << ' ';
        for (auto &w: res[i]) {
            k--;
            if (k < 0) break;
            cout << w << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}