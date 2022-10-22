#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 400100;
const int N = 400100;
int dfn[N], low[N], dfncnt, s[N], in_stack[N], tp;
int scc[N], sc;
int sz[N];
vector<int> g[V];
void tarjan(int u) {
  low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stack[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sc;
    while (s[tp] != u) {
      scc[s[tp]] = sc;
      sz[sc]++;
      in_stack[s[tp]] = 0;
      --tp;
    }
    scc[s[tp]] = sc;
    sz[sc]++;
    in_stack[s[tp]] = 0;
    --tp;
  }
}

vector<int> G[V];
int is[V], has[V];
vector<int> r[V];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char t[V];
int a[V], n, m, dg[V], b[V],Q[V];
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", t);
            for (int j = 0; j < m; ++j) {
                if(t[j] == '.') a[i * m + j] = 0;
                else a[i * m + j] = 1;
            }
        }
        for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
        dfncnt = 0;
        sc = 0;
        tp = 0;
        memset(in_stack, 0, sizeof(in_stack));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(is, 0, sizeof(is));
        memset(has, 0, sizeof(has));
        memset(sz, 0, sizeof(sz));
        memset(dg, 0, sizeof(dg));
        for (int i = 0; i < n * m; ++i) g[i].clear();
        for (int i = 0; i < n * m; ++i) {
            int x = i / m;
            int y = i % m;
            for (int j = 0; j < 4; ++j) {
                int tx = x + dx[j];
                int ty = y + dy[j];
                if (tx < 0 || tx >= n) continue;
                if (ty < 0 || ty >= m) continue;
                int k = tx * m + ty;
                if (a[k] == 1) g[i].PB(k);
                else if (j == 1) g[i].PB(k);
            }
        }
        set<PII> es;
        for (int i = 0; i < n * m; ++i) if (!dfn[i]) tarjan(i);
        for (int i = 1; i <= sc; ++i) G[i].clear();
        for (int i = 0; i < n * m; ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                int k = g[i][j];
                //printf("E %d %d %d %d\n", i, k, scc[i], scc[k]);
                if (scc[i] == scc[k]) continue;
                if (es.find({scc[i], scc[k]}) == es.end()) {
                    ++dg[scc[k]];
                    G[scc[i]].PB(scc[k]);
                    es.insert({scc[i], scc[k]});
                    //printf("ES1 %d %d\n", scc[i], scc[k]);
                }
            }
        }
        for (int i = 0; i < n * m; ++i) {
            if (a[i] == 0) continue;
            is[scc[i]] = 1;
        }
        int ans = 0;
        int top = 0, tail = 0;
        for (int i = 1; i <= sc; ++i) {
            if (dg[i] == 0) Q[++tail] = i;
        }
        while (top != tail) {
            int u = Q[++top];
            if (is[u] && !has[u]) ++ans;
            if (is[u]) has[u] = 1;
            for (int i = 0; i < G[u].size(); ++i) {
                int v = G[u][i];
                //printf("ES %d %d\n", u, v);
                has[v] |= has[u];
                --dg[v];
                if (dg[v] == 0) Q[++tail] = v;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
5 7
#....#.
.#.#...
#....#.
#....##
#.#....
4 1 1 1 0 3 1

3 3
#.#
#..
##.
3 1 1
*/