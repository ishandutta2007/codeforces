#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct segment_tree {
    struct Node {
        int mx;
        int mn;
        int upd;

        void combine(const Node &a, const Node &b) {
            mx = max(a.mx, b.mx);
            mn = min(a.mn, b.mn);
        }

        void check(int x) {
            mx += x;
            mn += x;
            upd += x;
        }

        Node(int x = 0) : mx(x), mn(x), upd(0) {}
    };

    vector<Node> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void build(vector<int> &a) {
        build(a.size());
        make(1, 0, n, a);
    }

    void make(int v, int l, int r, vector<int> &a) {
        if (l + 1 == r) {
            tree[v].check(a[l]);
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make(v << 1 | 1, (l + r) >> 1, r, a);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void push(int v) {
        if (!tree[v].upd) return;
        tree[v << 1].check(tree[v].upd);
        tree[v << 1 | 1].check(tree[v].upd);
        tree[v].upd = 0;
    }

    void upd(int v, int l, int r, int lq, int rq, int x) {
        if (lq >= r || rq <= l) return;
        if (lq <= l && r <= rq) {
            tree[v].check(x);
            return;
        }
        push(v);
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd(v << 1 | 1, (l + r) >> 1, r, lq, rq, x);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    Node get(int v, int l, int r, int lq, int rq) {
        if (lq <= l && r <= rq) return tree[v];
        Node res;
        res.mn = INFi;
        res.mx = -INFi;
        if (l >= rq || r <= lq) return res;
        push(v);
        res.combine(get(v << 1, l, (l + r) >> 1, lq, rq),
                    get(v << 1 | 1, (l + r) >> 1, r, lq, rq));
        return res;
    }

    Node get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }

    int findL(int v, int l, int r, int lq, int x) {
        if (r <= lq || tree[v].mx < x) return -1;
        if (l + 1 == r) return l;
        push(v);
        auto a = findL(v << 1, l, (l + r) >> 1, lq, x);
        if (a != -1) return a;
        return findL(v << 1 | 1, (l + r) >> 1, r, lq, x);
    }

    int findR(int v, int l, int r, int rq, int x) {
        if (l >= rq || tree[v].mx < x) return -1;
        if (l + 1 == r) return l;
        push(v);
        auto a = findR(v << 1 | 1, (l + r) >> 1, r, rq, x);
        if (a != -1) return a;
        return findR(v << 1, l, (l + r) >> 1, rq, x);
    }

    int findL(int lq, int x) {
        return findL(1, 0, n, lq, x);
    }

    int findR(int rq, int x) {
        return findR(1, 0, n, rq, x);
    }

    void upd(int lq, int rq, int x) {
        upd(1, 0, n, lq, rq, x);
    }
};

vector<int> g[maxN];
char ch[maxN];
int tin[maxN];
int tout[maxN];
int ord[maxN];
int sz[maxN];
int T = 0;
const int LG = 19;
int up[maxN][LG];
int h[maxN];
int head[maxN];
int pr[maxN];


void dfs_sz(int v) {
    sz[v] = 1;
    for (auto &u : g[v]) {
        dfs_sz(u);
        sz[v] += sz[u];
    }
    sort(all(g[v]), [&](const int &i, const int &j) { return sz[i] > sz[j]; });
}

void dfs(int v) {
    ord[T] = v;
    tin[v] = T++;
    for (int j = 1; j < LG; ++j) up[v][j] = up[up[v][j - 1]][j - 1];
    for (auto &u : g[v]) {
        up[u][0] = v;
        h[u] = h[v] + 1;
        if (u == g[v][0]) {
            head[u] = head[v];
            pr[u] = pr[v];
        } else {
            head[u] = T;
            pr[u] = v;
        }
        dfs(u);
    }
    tout[v] = T;
}


int lca(int v, int u) {
    if (h[v] < h[u]) swap(u, v);
    for (int i = LG - 1; i >= 0; --i) {
        if (h[up[v][i]] >= h[u]) v = up[v][i];
    }
    if (u == v) return v;
    for (int i = LG - 1; i >= 0; --i) {
        if (up[v][i] != up[u][i]) v = up[v][i], u = up[u][i];
    }
    return up[v][0];
}

segment_tree stch[26];
segment_tree st;

void upd(int v, int x) {
    while (v) {
        st.upd(head[v], tin[v] + 1, x);
        v = pr[v];
    }
}

void add(int i) {
    if (ch[i] == '?') return;
    int j = ch[i] - 'a';
    int lq = tin[i];
    int rq = tout[i];
    stch[j].upd(lq, rq, 1);
    int mx = stch[j].get(lq, rq).mx;
    int R = stch[j].findL(rq, mx);
    int L = stch[j].findR(lq, mx);
    int to = 0;
    if (L != -1) {
        int w = lca(ord[L], i);
        if (h[w] >= h[to]) to = w;
    }
    if (R != -1) {
        int w = lca(ord[R], i);
        if (h[w] >= h[to]) to = w;
    }
    upd(i, -1);
    if (to != 0) upd(to, 1);
    st.upd(tin[i], tin[i] + 1, 1);
}

void del(int i) {
    if (ch[i] == '?') return;
    int j = ch[i] - 'a';
    int lq = tin[i];
    int rq = tout[i];
    int mx = stch[j].get(lq, rq).mx;
    int R = stch[j].findL(rq, mx);
    int L = stch[j].findR(lq, mx);
    int to = 0;
    if (L != -1) {
        int w = lca(ord[L], i);
        if (h[w] >= h[to]) to = w;
    }
    if (R != -1) {
        int w = lca(ord[R], i);
        if (h[w] >= h[to]) to = w;
    }
    stch[j].upd(lq, rq, -1);
    upd(i, 1);
    if (to != 0) upd(to, -1);
    st.upd(tin[i], tin[i] + 1, -1);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
        cin >> ch[i];
    }
    dfs_sz(1);
    dfs(1);
    int must = -1;
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        if (g[i].empty()) {
            if (must == -1) must = h[i];
            if (h[i] != must) ok = false;
        }
    }
    if (!ok) {
        range(_, q) {
            cout << "Fou\n";
        }
        return;
    }
    {
        vector<int> vals;
        range(i, T) {
            vals.push_back(must - h[ord[i]]);
        }
        st.build(vals);
    }
    range(j, 26) stch[j].build(n);
    for (int i = 2; i <= n; ++i) {
        add(i);
    }
    assert(T == n);
    range(_, q) {
        int v;
        char c;
        cin >> v >> c;
        if (ch[v] != c) {
            del(v);
            ch[v] = c;
            add(v);
        }
        if (st.get(0, n).mn < 0) {
            cout << "Fou\n";
            continue;
        }
        ll ans = 0;
        int have = st.get(0, 1).mx;
        range(j, 26) {
            ans += 1ll * (j + 1) * (stch[j].get(0, n).mx + have);
        }
        cout << "Shi ";
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}