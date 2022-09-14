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
typedef long long ll;
typedef long double ld;
  
using namespace std;

const int N = 300002;
vector<pair<int, int>> g[N];
vector<int> ng[N];
int tin[N], tup[N], par[N], isb[N], col[N], mp[N];
int n, m, ct, ans;

void dfs(int v, int p) {
    par[v] = p;
    tin[v] = ++ct;
    tup[v] = tin[v];
    for (auto u : g[v]) {
        if (u.first == p)
            continue;
        if (tin[u.first]) {
            tup[v] = min(tup[v], tin[u.first]);
            continue;
        }
        dfs(u.first, v);
        tup[v] = min(tup[v], tup[u.first]);
    }
    for (auto u : g[v])
        if (par[u.first] == v && tup[u.first] > tin[v])
            isb[u.second] = 1;
}

void dfs2(int v, int cc) {
    col[v] = cc;
    for (auto u : g[v])
        if (!col[u.first] && !isb[u.second])
            dfs2(u.first, cc);
}

void dfs3(int v, int p) {
    int m1 = 0, m2 = 0;
    for (int u : ng[v]) {
        if (u == p)
            continue;
        dfs3(u, v);
        if (mp[u] > m1) {
            m2 = m1;
            m1 = mp[u];
        }
        else if (mp[u] > m2)
            m2 = mp[u];
    }
    mp[v] = m1 + 1;
    ans = max(ans, m1 + m2);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    dfs(1, -1);
    int cc = 0;
    for (int i = 1; i <= n; i++)
        if (!col[i])
            dfs2(i, ++cc);
    for (int i = 1; i <= n; i++)
        for (auto u : g[i])
            if (isb[u.second]) {
                ng[col[i]].push_back(col[u.first]);
            }
    dfs3(1, -1);
    printf("%d", ans);
}