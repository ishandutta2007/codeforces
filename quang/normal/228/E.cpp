#include <bits/stdc++.h>

using namespace std;

const int V = 210;

inline int pos(int u) { return u << 1; }
inline int neg(int u) { return u << 1 | 1; } 
struct TwoSAT {
    //ZERO-indexed
    int n;
    int numComp;
    vector<int> adj[V];
    int low[V], num[V], root[V], cntTarjan;
    vector<int> stTarjan;
    int color[V];

    TwoSAT(int n) : n(n * 2) {
        memset(root, -1, sizeof root);
        memset(low, -1, sizeof low);
        memset(num, -1, sizeof num);
        memset(color, -1, sizeof color);
        cntTarjan = 0;
        stTarjan.clear();
    }

    // u | v
    void addEdge(int u, int v) {
        adj[u ^ 1].push_back(v);
        adj[v ^ 1].push_back(u);
    }

    void tarjan(int u) {
        stTarjan.push_back(u);
        num[u] = low[u] = cntTarjan++;
        for (int v : adj[u]) {
            if (root[v] != -1) continue;
            if (low[v] == -1) tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        if (low[u] == num[u]) {
            while (1) {
                int v = stTarjan.back();
                stTarjan.pop_back();
                root[v] = numComp;
                if (u == v) break;
            }
            numComp++;
        }
    }

    bool solve() {
        for (int i = 0; i < n; i++) if (root[i] == -1) tarjan(i);
        for (int i = 0; i < n; i += 2) {
            if (root[i] == root[i ^ 1]) return 0;
            color[i >> 1] = (root[i] < root[i ^ 1]);
        }
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    TwoSAT t(n);
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        if (c) {
            t.addEdge(neg(u), pos(v));
            t.addEdge(neg(v), pos(u));
        } else {
            t.addEdge(pos(u), pos(v));
            t.addEdge(neg(u), neg(v));
        }
    }
    if (!t.solve()) {
        cout << "Impossible\n";
    } else {
        vector<int> res;
        for (int i = 0; i < n; i++) if (t.color[i]) res.push_back(i + 1);
            cout << res.size() << '\n';
        for (int u : res) cout << u << ' ';
            cout << endl;
    }
    return 0;
}