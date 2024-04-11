#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

struct edge {
    int u, v, w, i;
    edge(int u, int v, int w, int i) : u(u), v(v), w(w), i(i) {}
};

class UnionFind {
public:
    vector<int> p, r;
    explicit UnionFind(int n = N) {
        p.resize(n + 1);
        iota(all(p), 0);
        r.resize(n + 1, 1);
    }
    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }
    void union_find(int x, int y) {
        int l1 = find(x);
        int l2 = find(y);

        if (l1 != l2) {
            if (r[l1] > r[l2])
                p[l2] = l1;
            else if (r[l1] < r[l2])
                p[l1] = l2;
            else {
                p[l2] = l1;
                r[l1]++;
            }
        }
    }
};

int n, ans[N], d[N];
vector<pair<int, int>> g[N];
vector<edge> edges;

bool visited[N];

void dfs(int x, int e, int dep) {
    visited[x] = true;
    d[x] = dep;

    for (auto &[v, i]: g[x]) {
        if (!visited[v]) {
            dfs(v, i, dep + 1);
            d[x] = min(d[x], d[v]);
        }
        else if (i != e)
            d[x] = min(d[x], d[v]);
    }
    if (d[x] == dep and e != -1)
        ans[edges[e].i] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    edges.reserve(m);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(u, v, w, i);
    }

    sort(all(edges), [&] (edge e1, edge e2) {
        return e1.w < e2.w;
    });

    UnionFind uf = UnionFind(n);
    for (int i = 0; i < m;) {
        int j;

        for (j = i; j < m and edges[i].w == edges[j].w; j++) {
            int s1 = uf.find(edges[j].u), s2 = uf.find(edges[j].v);
            if (uf.find(edges[j].u) == uf.find(edges[j].v)) {
                continue;
            }
            g[s1].emplace_back(s2, j);
            g[s2].emplace_back(s1, j);
            ans[edges[j].i] = 1;
        }

        for (j = i; j < m and edges[i].w == edges[j].w; j++) {
            if (!visited[uf.find(edges[j].u)])
                dfs(uf.find(edges[j].u), -1, 0);
        }

        for (j = i; j < m and edges[i].w == edges[j].w; j++) {
            int s1 = uf.find(edges[j].u), s2 = uf.find(edges[j].v);
            g[s1].clear();
            g[s2].clear();
            visited[s1] = visited[s2] = false;
            uf.union_find(edges[j].u, edges[j].v);
        }
        i = j;
    }

    for (int i = 0; i < m; i++) {
        if (ans[i] == 0)
            cout << "none\n";
        else if (ans[i] == 1)
            cout << "at least one\n";
        else cout << "any\n";
    }
    return 0;
}