// Link: https://codeforces.com/contest/342/problem/E
#include <bits/stdc++.h>
using namespace std;

struct CentroidDecomposition {
    vector<vector<int>> G;
    vector<bool> done;
    vector<int> sz, par;
    vector<int> cen; // direct centroid anc
    vector<vector<int>> dist; // distance to all centroid ancs (highes to lowest)

    vector<int> ans;

    CentroidDecomposition(int n = 0) {
        resize(n);
    }

    void resize(int n) {
        G = dist = vector<vector<int>>(n);
        ans = sz = par = cen = vector<int>(n), 0;
        done = vector<bool>(n, false);
    }

    void addEdge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void dfs(int n) {
        sz[n] = 1;
        for (auto i : G[n]) if (i != par[n] && !done[i]) {
            par[i] = n; dfs(i);
            sz[n] += sz[i];
        }
    }

    int centroid(int n) {
        par[n] = -1; dfs(n);
        int N = sz[n];

        while (true) {
            pair<int, int> mx = {-1, -1};
            for (auto i : G[n]) if (i != par[n] && !done[i]) {
                mx = max(mx, {sz[i], i});
            }
            if (mx.first * 2 <= N) {
                return n;
            }
            n = mx.second;
        }
    }

    void genDist(int n, int p) {
        dist[n].push_back(dist[p].back() + 1);
        for (auto i : G[n]) if (i != p && !done[i]) {
            genDist(i, n);
        }
    }

    void gen(int n, int p) {
        done[n = centroid(n)] = 1; cen[n] = p;
        dist[n].push_back(0);
        for (auto i : G[n]) if (!done[i]) {
            genDist(i, n);
        }
        for (auto i : G[n]) if (!done[i]) {
            gen(i, n);
        }
    }

    void init() {
        gen(0, -1);
        fill(begin(ans), end(ans), 1e9);
    }

    void update(int v) {
        int x = v;
        do {
            ans[v] = min(ans[v], dist[x][dist[v].size() - 1]);
            v = cen[v];
        } while (v != -1);
    }

    int query(int v) {
        int res = 1e9;
        int x = v;
        do {
            res = min(res, ans[v] + dist[x][dist[v].size() - 1]);
            v = cen[v]; 
        } while (v != -1);
        return res;
    }

};

using CD = CentroidDecomposition;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, Q;
    CD CD;

    cin >> N >> Q;
    CD.resize(N);

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        CD.addEdge(u, v);
    }

    for (CD.init(), CD.update(0); Q > 0; Q--) {
        int t = 0, v = 0;
        cin >> t >> v;
        v--;
        if (t == 1) {
            CD.update(v);
        } else if (t == 2) {
            cout << CD.query(v) << "\n";
        }
    }
    return 0;
}