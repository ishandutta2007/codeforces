#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 100001, M = N * 2, L = 19;
int tin[N], tup[N], used[N], ct;
vector<int> g[N], ng[M];
int d[M], up[L][M], cn;

void dfs(int v, int p) {
    tup[v] = tin[v] = ++ct;
    for (int u : g[v]) {
        if (u == p)
            continue;
        if (tin[u])
            tup[v] = min(tup[v], tin[u]);
        else {
            dfs(u, v);
            tup[v] = min(tup[v], tup[u]);
        }
    }
}

void dfs2(int v, int p) {
    used[v] = 1;
    if (v != 1) {
        if (tup[v] >= tin[p]) {
            ng[v].push_back(++cn);
            ng[cn].push_back(v);
            ng[p].push_back(cn);
            ng[cn].push_back(p);
        }
        else {
            ng[v].push_back(ng[p][0]);
            ng[ng[p][0]].push_back(v);
        }
    }
    for (int u : g[v])
        if (!used[u])
            dfs2(u, v);
}

void dfs3(int v, int p) {
    up[0][v] = p;
    for (int u : ng[v]) {
        if (u == p)
            continue;
        d[u] = d[v] + 1;
        dfs3(u, v);
    }
}

int lca(int u, int v) {
    for (int i = L - 1; i >= 0; i--)
        if (d[up[i][u]] >= d[v])
            u = up[i][u];
    for (int i = L - 1; i >= 0; i--)
        if (d[up[i][v]] >= d[u])
            v = up[i][v];
    for (int i = L - 1; i >= 0; i--)
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    return u == v ? u : up[0][u];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("wikipidia.in", "r", stdin); 
    //freopen("wikipidia.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q, u, v;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cn = n;
    dfs2(1, 1);
    dfs3(1, 1);
    for (int i = 0; i < L - 1; i++)
        for (int j = 1; j <= cn; j++)
            up[i + 1][j] = up[i][up[i][j]];
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &u, &v);
        printf("%d\n", (d[u] + d[v] - d[lca(u, v)] * 2) / 2);
    }
}