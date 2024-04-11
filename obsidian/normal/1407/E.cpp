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

const int V = 500100;
vector<PII> g[V];

int d[V][2];
int Q[V * 2], vis[V * 2];

int n, m, u, v, w;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            if (u == v) continue;
            g[v].PB(MP(u, w));
        }
        memset(d, -1, sizeof(d));
        memset(vis, 0, sizeof(vis));
        int top = 0, tail = 0;
        d[n][0] = d[n][1] = 0;
        vis[n] = 1;
        Q[++tail] = n;
        while (top != tail) {
            u = Q[++top];
            for (int i = 0; i < g[u].size(); ++i) {
                v = g[u][i].fi;
                w = g[u][i].se;
                if (d[v][w] == -1) {
                    d[v][w] = max(d[u][0], d[u][1]) + 1;
                    if (d[v][1 - w] != -1 && !vis[v]) {
                        Q[++tail] = v;
                        vis[v] = 1;
                    }
                }
            }
        }
        if (!vis[1]) {
            puts("-1");
            for (int i = 1; i <= n; ++i) if (d[i][0] == -1) putchar('0'); else putchar('1');
            puts("");
        }
        else {
            printf("%d\n", max(d[1][0], d[1][1]));
            for (int i = 1; i <= n; ++i) {
                if (d[i][0] == -1 || (d[i][1] != -1 && d[i][0] > d[i][1])) putchar('0'); else putchar('1');
            }
            puts("");
        }
    }
    return 0;
}

/*
3 4
1 2 0
1 3 1
2 3 0
2 3 1
4 8
1 1 0
1 3 0
1 3 1
3 2 0
2 1 0
3 4 1
2 4 0
2 4 1
5 10
1 2 0
1 3 1
1 4 0
2 3 0
2 3 1
2 5 0
3 4 0
3 4 1
4 2 1
4 5 0
*/