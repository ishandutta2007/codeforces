// Link: https://codeforces.com/contest/321/problem/C

#include <bits/stdc++.h>
using namespace std;

struct CD {
    vector<vector<int>> G, dist;
    vector<int> done, par, sz, cen;
    vector<char> ans;

    CD(int n) {
        resize(n);
    }

    void resize(int n) {
        G = dist = vector<vector<int>>(n);
        done = par = sz = cen = vector<int>(n);
        ans = vector<char>(n, '-');
    }

    void addEdge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void dfs(int n) {
        sz[n] = 1;
        for (auto i : G[n]) if (!done[i] && i != par[n]) {
            par[i] = n;
            dfs(i);
            sz[n] += sz[i];
        }
    }

    int centroid(int n) {
        par[n] = -1;
        dfs(n);
        int N = sz[n];
        while (true) {
            pair<int, int> mx = {-1, -1};
            for (auto i : G[n]) if (!done[i] && i != par[n]) {
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
        for (auto i : G[n]) if (!done[i] && i != p) {
            genDist(i, n);
        }
    }

    void gen(int n, int p) {
        done[n = centroid(n)] = 1;
        cen[n] = p;
        dist[n].push_back(0);
        for (auto i : G[n]) if (!done[i]) genDist(i, n);
        for (auto i : G[n]) if (!done[i]) gen(i, n);
    }

    void init() {
        gen(0, -1);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = dist[i].size() - 1 + 'A';
        }
    }

    void print() {
        for (auto i : ans) {
            cout << i << " ";
        }
    }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    
    CD CD(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        CD.addEdge(u, v);
    } 

    CD.init();
    CD.print();
    return 0;
}