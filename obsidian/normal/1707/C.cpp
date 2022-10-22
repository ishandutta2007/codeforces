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
const int V = 200100;
const int M = 20;
vector<PII> E;
vector<int> g[V];
struct Node{int l, r;}e[3 * V];
bool cmp(Node x, Node y) {return x.l <y.l;}
int f[V], L[V], R[V], d[V], ans[V];

int fd(int x) {
    if (x != f[x]) f[x] = fd(f[x]);
    return f[x];
}

int idx;
int _fa[V][22];
void dfs(int u, int fa) {
    ++idx;
    L[u] = idx;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        d[v] = d[u] + 1;
        _fa[v][0] = u;
        dfs(v, u);
    }
    R[u] = idx;
}

int n, m, en, u, v;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) f[i] = i, g[i].clear();
        E.clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            int pu = fd(u);
            int pv = fd(v);
            if (pu == pv) E.PB(MP(u, v));
            else {g[u].PB(v); g[v].PB(u);f[pu] = pv;}
        }
        en = 0;
        idx = 0;
        d[1] = 0;
        //puts("OK");
        _fa[1][0] = -1;
        dfs(1, -1);
        for (int j = 1; j <= M; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (_fa[i][j - 1] == -1) _fa[i][j] = -1;
                else _fa[i][j] = _fa[_fa[i][j - 1]][j - 1];
            }
        }
        //for (int i = 1; i <= n; ++i) printf("LR %d %d %d\n", i, L[i], R[i]);
        for (int i = 0; i < E.size(); ++i) {
            u = E[i].fi;
            v = E[i].se;
            if (d[u] > d[v]) swap(u, v);
            if (L[v] >= L[u] && R[v] <= R[u]) {
                int dt = d[v] - d[u] - 1;
                u = v;
                for (int j = 0; j <= M; ++j) {
                    if (dt & 1) u = _fa[u][j];
                    dt /= 2;
                }
                e[en++] = {L[u], L[v] - 1};
                e[en++] = {R[v] + 1, R[u]};
                //e[en++] = {1, L[u] - 1};
                //e[en++] = {R[u] + 1, n};
            } else {
                if (R[u] > R[v]) swap(u, v);
                e[en++] = {1, L[u] - 1};
                e[en++] = {R[u] + 1, L[v] - 1};
                e[en++] = {R[v] + 1, n};
            }
        }
        //for (int i = 0; i < en; ++i) printf("E %d %d\n", e[i].l, e[i].r);
        sort(e, e + en, cmp);
        int cur = 0;
        int pos = 0;
        for (int i = 1; i <= n; ++i) {
            while (pos < en && e[pos].l <= i) {
                if (e[pos].l <= e[pos].r) cur = max(cur, e[pos].r);
                ++pos;
            }
            if (cur < i) ans[i] = 1;
            else ans[i] = 0;
        }
        for (int i = 1; i <= n; ++i) printf("%d", ans[L[i]]); puts("");
    }
    return 0;
}

/*
5 5
1 2
3 5
1 3
3 2
4 2

10 11
1 2
2 5
3 4
4 2
8 1
4 5
10 5
9 5
8 2
5 7
4 6
*/