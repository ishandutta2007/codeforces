/**
 * Author   : rama_pang
 * Problem  : https://codeforces.com/contest/375/problem/D
 * Time     : O(N log^2 N)
 * Memory   : O(N)
**/

#include <bits/stdc++.h>
using namespace std;

template<int SZ>
struct BIT {
    int tree[SZ] = {};
    void update(int p, int x) {
        if (p <= 0) return;
        for (int i = p; i < SZ; i += (i & -i)) tree[i] += x;
    }
    int _query(int p) { // return sum of [1, p]
        int res = 0;
        for (int i = p; i > 0; i -= (i & -i)) res += tree[i];
        return res;
    }
    int query(int p) {
        return _query(SZ - 1) - _query(p - 1);
    }
};

const int NMAX = 100005;

int N, M;
int color[NMAX];
int ans[NMAX];
int sz[NMAX];

BIT<NMAX> bit;
vector<int> adj[NMAX];
vector<pair<int, int>> query[NMAX]; // query[v] = (k, id)

int colorCnt[NMAX];

void dfsSz(int n, int p) {
    sz[n] = 1;
    if (p) {
        adj[n].erase(find(begin(adj[n]), end(adj[n]), p));
    }
    for (auto &i : adj[n]) {
        dfsSz(i, n);
        sz[n] += sz[i];
        if (sz[i] > sz[adj[n][0]]) swap(i, adj[n][0]);
    }
}

void add(int n, int x) {
    bit.update(colorCnt[color[n]], -1);
    colorCnt[color[n]] += x;
    bit.update(colorCnt[color[n]], 1);

    for (auto &i : adj[n]) {
        add(i, x);
    }
}

void dfs(int n, bool keep) {
    for (auto &i : adj[n]) if (i != adj[n][0]) dfs(i, 0); // light child
    for (auto &i : adj[n]) if (i == adj[n][0]) dfs(i, 1); // heavy child
    
    for (auto &i : adj[n]) if (i != adj[n][0]) { // each node is traversed O(log n) times, since it is a part of only O(log n) light edges in path from n to root (HLD argument).
        add(i, 1);
    }

    bit.update(colorCnt[color[n]], -1);
    colorCnt[color[n]]++;
    bit.update(colorCnt[color[n]], 1);
    
    for (auto &i : query[n]) {
        ans[i.second] = bit.query(i.first);
    }

    if (!keep) add(n, -1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> color[i];
    }
    for (int i = 2; i <= N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for (int i = 1; i <= M; i++) {
        int v, k;
        cin >> v >> k;
        query[v].emplace_back(k, i);
    }

    dfsSz(1, 0);
    dfs(1, 1);

    for (int i = 1; i <= M; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}