#include <bits/stdc++.h>
using namespace std;
constexpr int SZ = 2e5;

template<int MX>
struct LCATree {
    static const int BITS = 32 - __builtin_clz(MX);

    int N, R;
    vector<int> adj[MX];
    int par[MX][BITS];
    int depth[MX];
    int sz[MX];


    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    void dfs(int u, int p) {
        par[u][0] = p;
        depth[u] = depth[p] + 1;
        sz[u] = 1;
        for (auto &v : adj[u]) if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }

    void init(int _N, int _R) {
        N = _N;
        R = _R;
        dfs(R, 0);
        for (int j = 1; j < BITS; j++) {
            for (int i = 1; i <= N; i++) {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }


    int getAnc(int u, int dist) {
        for (int i = BITS - 1; i >= 0; i--) {
            if (dist & (1 << i)) u = par[u][i];
        }
        return u;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = getAnc(u, depth[u] - depth[v]);
        for (int i = BITS - 1; i >= 0; i--) {
            if (par[u][i] != par[v][i]) {
                u = par[u][i], v = par[v][i];
            }
        }
        return u == v ? u : par[u][0];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    
    LCATree<SZ> tree;

    for (int i = 0; i + 1 < N; i++) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }

    tree.init(N, 1);
    int Q;
    cin >> Q;
    for (int qi = 0; qi < Q; qi++) {
        int x, y;
        cin >> x >> y;
        int d = tree.dist(x, y);
        if (d & 1) { // distance is odd
            cout << 0 << "\n";
            continue;
        }

        if (tree.depth[x] < tree.depth[y]) swap(x, y);
        if (x == y) {
            cout << N << "\n";
        } else if (tree.depth[x] == tree.depth[y]) { // if meet
            int exclude[2] = {tree.sz[tree.getAnc(x, d / 2 - 1)], tree.sz[tree.getAnc(y, d / 2 - 1)]};
            cout << N - exclude[0] - exclude[1] << "\n";
        } else {
            int exclude_below = tree.sz[tree.getAnc(x, d / 2 - 1)];
            int exclude_above = N - tree.sz[tree.getAnc(x, d / 2)];
            cout << N - exclude_above - exclude_below << "\n";
        }
    }
    return 0;
}