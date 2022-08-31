#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


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
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

const int maxM = 1e7;
vector<int> g1[maxM], g2[maxM];
vector<int> g[maxN];

int up[maxN][18];
int h[maxN];
int TT = 0;
int tin[maxN], tout[maxN];

void dfs_lca(int v, int p) {
    up[v][0] = p;
    tin[v] = TT++;
    for (int i = 1; i < 18; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    for (auto &u : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs_lca(u, v);
    }
    tout[v] = TT;
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(u, v);
    for (int i = 17; i >= 0; --i) {
        if (h[up[v][i]] >= h[u]) v = up[v][i];
    }
    if (u == v) return v;
    for (int i = 17; i >= 0; --i) {
        if (up[v][i] != up[u][i]) v = up[v][i], u = up[u][i];
    }
    return up[v][0];
}

int kth_anc(int v, int k) {
    range(i, 18) {
        if ((1 << i) & k) v = up[v][i];
    }
    return v;
}

bool check(int v, int p) {
    if (v == 0) return false;
    return tin[p] <= tin[v] && tout[v] <= tout[p];
}


int vA[maxN], vB[maxN];
int P = 1;
int T = 1;

int unio(int a, int b) {
    if (b == -1) return a;
    if (a == -1) return b;
    g1[a * 2].push_back(b * 2 + 1);
    g1[b * 2].push_back(a * 2 + 1);
    int c = P++;
    g1[c * 2 + 1].push_back(a * 2 + 1);
    g1[a * 2].push_back(c * 2);
    g1[b * 2].push_back(c * 2);
    g1[c * 2 + 1].push_back(b * 2 + 1);
    return c;
}

struct Node {
    int p;
    Node *l, *r;

    Node() : p(-1), l(nullptr), r(nullptr) {}

    void update() {
        p = -1;
        if (l) p = unio(p, l->p);
        if (r) p = unio(p, r->p);
    }
};

vector<int> ended[maxN];
vector<int> opened[maxN];
int M;

void upd(Node *&v, int l, int r, int i) {
    if (r <= i || l > i) return;
    if (!v) v = new Node();
    if (l + 1 == r) {
        if (v->p == -1) {
            v->p = i;
        } else {
            v->p = -1;
        }
        return;
    }
    upd(v->l, l, (l + r) >> 1, i);
    upd(v->r, (l + r) >> 1, r, i);
    v->update();
}

Node * merge(Node *a, Node *b, int l, int r) {
    if (!a) return b;
    if (!b) return a;
    if (l + 1 == r) {
        if (a->p != -1) return a;
        return b;
    }
    a->l = merge(a->l, b->l, l, (l + r) >> 1);
    a->r = merge(a->r, b->r, (l + r) >> 1, r);
    a->update();
    return a;
}

Node *dfs(int v, int p) {
    Node *tr = nullptr;
    for (auto &u : g[v]) {
        if (u == p) continue;
        auto w = dfs(u, v);
        tr = merge(tr, w, 1, M);
    }
    T++;
    for (auto &i : opened[v]) {
        upd(tr, 1, M, i);
    }
    for (auto &i : ended[v]) {
        upd(tr, 1, M, i);
    }
    return tr;
}

vector<int> ts;
bool used[maxM];

void dfs1(int v) {
    used[v] = true;
    for (auto &u : g2[v]) {
        if (used[u]) continue;
        dfs1(u);
    }
    ts.push_back(v);
}

int comp[maxM];

void dfs2(int v, int c) {
    comp[v] = c;
    for (auto &u : g1[v]) {
        if (comp[u]) continue;
        dfs2(u, c);
    }
}

bool solve2SAT() {
    assert(P * 2 < maxM);
    range(v, P * 2) {
        for (auto &u : g1[v]) {
            g2[u].push_back(v);
        }
    }
    range(v, P * 2) {
        if (used[v]) continue;
        dfs1(v);
    }
    reverse(all(ts));
    int C = 1;
    for (auto &v : ts) {
        if (comp[v]) continue;
        dfs2(v, C++);
    }
    range(v, P * 2) {
        if (comp[v] == comp[v ^ 1]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs_lca(1, 1);
    int m;
    cin >> m;
    range(i, m) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g1[P * 2 + 1].push_back(P * 2 + 2);
        g1[P * 2 + 3].push_back(P * 2);
        range(_, 2) {
            int cur = P++;
            vA[cur] = a;
            vB[cur] = b;
            int w = lca(a, b);
            if (w != a) {
                int w1 = kth_anc(a, h[a] - h[w] - 1);
                opened[a].push_back(cur);
                ended[w1].push_back(cur);
            }
            if (w != b) {
                int w2 = kth_anc(b, h[b] - h[w] - 1);
                opened[b].push_back(cur);
                ended[w2].push_back(cur);
            }
            swap(a, c);
            swap(b, d);
        }
    }
    M = P;
    dfs(1, -1);
    if (!solve2SAT()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    range(i, m) {
        int a = i * 2 + 1;
        int b = i * 2 + 2;
        if (comp[a * 2] < comp[a * 2 + 1]) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
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