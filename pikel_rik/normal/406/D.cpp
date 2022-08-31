#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

class Graph {
public:
    struct edge {
        int u, v;
        edge(int u, int v): u(u), v(v) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<int>> adj;

    Graph(): n(), m(), adj(), edges() {}
    Graph(int n): n(n), m(), adj(n), edges() {}

    const vector<int>& operator[](const int& x) const { return adj[x]; }
    vector<int>& operator[](const int &x) { return adj[x]; }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
        m++;
    }
};

template <typename T>
class SparseTable {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<vector<T>> mat;
    F f;
    SparseTable(): n(), mat(), f() {}

    template <typename U>
    SparseTable(const U& arr, int n, F f): n(n), f(f), mat((int)log2(n) + 1) {
        mat[0].resize(n);
        for (int i = 0; i < n; i++)
            mat[0][i] = T(arr[i]);
        for (int j = 1; j < mat.size(); j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i + (1 << j) <= n; i++) {
                mat[j][i] = f(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int j = 32 - __builtin_clz(r - l + 1) - 1;
        return f(mat[j][l], mat[j][r + 1 - (1 << j)]);
    }
};

class LCA {
public:
    int timer;
    vector<int> p, tin, tout, euler, lvl;
    SparseTable<int> st;

    LCA(const Graph& g, int root = 0): timer(0), p(g.n), tin(g.n), tout(g.n), lvl(g.n) {
        euler.reserve(2 * g.n - 1);
        p[root] = -1;
        dfs(root, g);
        st = SparseTable<int>(euler, 2 * g.n - 1, [&] (int x, int y) {
            return lvl[x] < lvl[y] ? x : y;
        });
    }

    void dfs(int x, const Graph& g) {
        tin[x] = timer++;
        euler.push_back(x);
        for (const int& i : g[x]) {
            if (i != p[x]) {
                p[i] = x;
                lvl[i] = lvl[x] + 1;
                dfs(i, g);
                euler.push_back(x);
            }
        }
        tout[x] = timer++;
    }

    int lca(int u, int v) {
        if (tin[u] > tin[v])
            swap(u, v);
        return st.query(tin[u], tin[v]);
    }

    int dist(int u, int v) {
        return lvl[u] + lvl[v] - 2 * lvl[lca(u, v)];
    }
};

const int N = 1e5 + 5;

int n, m, x[N], go[N];
ll y[N];

struct fraction {
    ll num, dem;
    fraction(ll num = 0, ll dem = 1): num(num), dem(dem) {}
    bool operator<(const fraction& lhs) {
        return num * lhs.dem < lhs.num * dem;
    }
};

fraction slope(int i, int j) {
    return fraction(y[j] - y[i], x[j] - x[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    vector<int> st = {n - 1};
    for (int i = n - 2; i >= 0; i--) {
        while (st.size() > 1 and slope(i, st[st.size() - 1]) < slope(i, st[st.size() - 2])) {
            st.pop_back();
        }
        go[i] = st.back();
        st.push_back(i);
    }

    Graph g(n);
    for (int i = 0; i < n - 1; i++) {
        g.addEdge(i, go[i]);
    }
    LCA l(g, n - 1);

    cin >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        cout << l.lca(--a, --b) + 1 << ' ';
    }
    return 0;
}