/**
 * Author   : rama_pang
 * Problem  : https://codeforces.com/problemset/problem/427/C
 * Time     : O(N + M)
 * Memory   : O(N + M)
**/

#include <bits/stdc++.h>
using namespace std;

template<int SZ>
struct SCC {
    int N, comp[SZ];
    vector<int> adj[SZ], rev[SZ];
    vector<int> bigComp, todo;
    int vis[SZ];

    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
        rev[v].emplace_back(u);
    }

    void dfs(int n) {
        vis[n] = 1;
        for (auto &i : adj[n]) if (!vis[i]) dfs(i);
        todo.emplace_back(n);
    }

    void dfs2(int n, int cmp) {
        comp[n] = cmp;
        for (auto &i : rev[n]) if (!comp[i]) dfs2(i, cmp);
    }

    void build(int n) {
        N = n;
        for (int i = 1; i <= N; i++) {
            vis[i] = comp[i] = 0;
        }
        for (int i = 1; i <= N; i++) if (!vis[i]) dfs(i);
        reverse(begin(todo), end(todo));
        for (auto &i : todo) if (!comp[i]) dfs2(i, i), bigComp.emplace_back(i);
    }
};

const int MAXN = 100005;

using lint = long long;

SCC<MAXN> scc;
lint cost[MAXN];
lint bigCompCost[MAXN];
lint bigCompCount[MAXN];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> cost[i];
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        scc.addEdge(u, v);
    }
    
    scc.build(N);

    for (int i = 1; i <= N; i++) bigCompCost[i] = 1e18;
    for (int i = 1; i <= N; i++) {
        bigCompCost[scc.comp[i]] = min(bigCompCost[scc.comp[i]], cost[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (cost[i] == bigCompCost[scc.comp[i]]) 
            bigCompCount[scc.comp[i]]++;
    }
    
    lint minCost = 0;
    lint ways = 1;
    lint MOD = 1e9 + 7;

    for (int i = 1; i <= N; i++) {
        if (bigCompCount[scc.comp[i]] > 0) {
            ways *= bigCompCount[scc.comp[i]];
            ways %= MOD;
            minCost += bigCompCost[scc.comp[i]];
            bigCompCount[scc.comp[i]] = 0;
        }
    }

    cout << minCost << " " << ways << "\n";
    return 0;

}