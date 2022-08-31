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
const int N = 100 + 5;

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

struct edge {
    int u, v, c;
    edge(int u, int v, int c): u(u), v(v), c(c) {}
};

int n;
vector<pair<int, int>> g[N];
vector<edge> edges;
vector<edge> comp[N];

int visited[N];

void bfs(int s1, int s2) {
    queue<int> q;
    q.push(s1);
    q.push(s2);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto &[v, c]: g[x]) {
            if (visited[v] == -1) {
                if (c == 0) {
                    if (visited[x] == 1)
                        visited[v] = 0;
                    else visited[v] = 1;
                }
                else {
                    if (visited[x] == 1)
                        visited[v] = 1;
                    else visited[v] = 0;
                }
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
        edges.emplace_back(u, v, c);
        uf.union_find(u, v);
    }

    for (int i = 0; i < m; i++) {
        comp[uf.find(edges[i].u)].push_back(edges[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (comp[i].empty()) continue;

        edge ed = comp[i].front();
        if (ed.c == 1) {
            for (int v = 1; v <= n; v++) {
                if (uf.find(v) == i)
                    visited[v] = -1;
            }
            visited[ed.u] = 0; visited[ed.v] = 0;
            bfs(ed.u, ed.v);

            bool ok = true;
            for (edge e : comp[i]) {
                if ((visited[e.u] + visited[e.v]) % 2 == e.c)
                    ok = false;
            }

            if (ok)
                continue;

            for (int v = 1; v <= n; v++) {
                if (uf.find(v) == i)
                    visited[v] = -1;
            }
            visited[ed.u] = 1; visited[ed.v] = 1;
            bfs(ed.u, ed.v);

            ok = true;
            for (edge e : comp[i]) {
                if ((visited[e.u] + visited[e.v]) % 2 == e.c)
                    ok = false;
            }

            if (!ok) {
                cout << "Impossible\n";
                return 0;
            }
        }
        else {
            for (int v = 1; v <= n; v++) {
                if (uf.find(v) == i)
                    visited[v] = -1;
            }
            visited[ed.u] = 1; visited[ed.v] = 0;
            bfs(ed.u, ed.v);

            bool ok = true;
            for (edge e : comp[i]) {
                if ((visited[e.u] + visited[e.v]) % 2 == e.c)
                    ok = false;
            }

            if (ok)
                continue;

            for (int v = 1; v <= n; v++) {
                if (uf.find(v) == i)
                    visited[v] = -1;
            }
            visited[ed.u] = 0; visited[ed.v] = 1;
            bfs(ed.u, ed.v);

            ok = true;
            for (edge e : comp[i]) {
                if ((visited[e.u] + visited[e.v]) % 2 == e.c)
                    ok = false;
            }

            if (!ok) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 1)
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " "; cout << "\n";
    return 0;
}