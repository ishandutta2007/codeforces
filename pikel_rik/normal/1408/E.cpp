#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 1e5 + 5;

class Graph {
public:
    struct edge {
        int u, v, w;
        edge(int u, int v, int w): u(u), v(v), w(w) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<pair<int, int>>> adj;

    Graph(): n(), m(), adj(), edges() {}
    Graph(int n): n(n), m(), adj(n), edges() {}

    const vector<pair<int, int>>& operator[](const int &x) const { return adj[x]; }
    vector<pair<int, int>>& operator[](const int &x) { return adj[x]; }

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        edges.emplace_back(u, v, w);
        m++;
    }
};

class UnionFind {
public:
    int n;
    vector<int> p, r;

    UnionFind(): n(), p(), r() {}
    UnionFind(int n): n(n), p(n), r(n) {
        iota(p.begin(), p.end(), 0);
    }
    size_t size() const {
        return n;
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    bool merge(int x, int y) {
        int l1 = find(x);
        int l2 = find(y);

        if (l1 == l2)
            return false;
        if (r[l1] > r[l2])
            p[l2] = l1;
        else if (r[l1] < r[l2])
            p[l1] = l2;
        else {
            p[l2] = l1;
            r[l1]++;
        }
        n--;
        return true;
    }
};

vector<int> Kruskal(const Graph& g) {
    UnionFind uf(g.n);

    vector<int> indices(g.m);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&] (const int& i, const int& j) {
        return g.edges[i].w > g.edges[j].w;
    });

    vector<int> mst;
    for (int i : indices) {
        if (uf.merge(g.edges[i].u, g.edges[i].v))
            mst.push_back(i);
    }
    return mst;
}

int n, m, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    Graph g(n + m);
    for (int i = 0, s; i < m; i++) {
        cin >> s;
        for (int j = 0, x; j < s; j++) {
            cin >> x; --x;
            g.addEdge(x, n + i, a[i] + b[x]);
        }
    }

    vector<bool> marked(g.m);
    for (int i : Kruskal(g)) {
        marked[i] = true;
    }

    ll ans = 0;
    for (int i = 0; i < g.m; i++) {
        if (!marked[i]) {
            ans += g.edges[i].w;
        }
    }
    cout << ans << '\n';
    return 0;
}