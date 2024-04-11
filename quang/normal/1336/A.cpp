#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 200010;

template<typename T>
struct Tree {
    int n;
    int curPos;
    vector<vector<pair<int, T>>> adj;
    vector<int> posIn;
    vector<int> posOut;
    vector<int> sz;
    vector<int> lv;
    vector<T> dist;
    vector<vector<int>> par;

    Tree(int n = -1) : n(n) {
        curPos = 0;
        adj.assign(n + 1, vector<pair<int, T>>());
        posIn.assign(n + 1, 0);
        posOut.assign(n + 1, 0);
        sz.assign(n + 1, 0);
        lv.assign(n + 1, 0);
        dist.assign(n + 1, 0);
        if (n > 0) par.assign((int)log2(n) + 1, vector<int>(n + 1, 0));
    }

    void addEdge(int u, int v, T cost = 1) {
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    void dfs(int u, int p) {
        posIn[u] = ++curPos;
        sz[u] = 1;
        lv[u] = lv[p] + 1;
        par[0][u] = p;
        for (int i = 1; i < par.size(); i++) par[i][u] = par[i - 1][par[i - 1][u]];

        for (auto e : adj[u]) {
            int v = e.first;
            T cost = e.second;
            if (v == p) continue;
            dist[v] = dist[u] + cost;
            dfs(v, u);
            sz[u] += sz[v];
        }

        posOut[u] = curPos;
    }

    int getLCA(int u, int v) {
        if (lv[u] < lv[v]) swap(u, v);
        int h = lv[u] - lv[v];
        for (int i = (int)par.size() - 1; i >= 0; i--) {
            if (h >> i & 1) u = par[i][u];
        }
        if (u == v) return u;
        for (int i = (int)par.size() - 1; i >= 0; i--) {
            if (par[i][u] != par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }
};
 
int n, k;
int val[N];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    Tree<int> t(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        t.addEdge(u, v);
    }
    t.dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        val[i] = t.lv[i] - t.sz[i];
    }
    sort(val + 1, val + n + 1, greater<int>());
    cout << accumulate(val + 1, val + k + 1, 0ll) << endl;
    return 0;
}