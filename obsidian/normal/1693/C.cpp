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
vector<int> g[V], Q[V * 2];
int dg[V], vis[V], d[V];
int n, m, u, v;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(dg, 0, sizeof(dg));
        memset(vis, 0, sizeof(vis));
        memset(d, -1, sizeof(d));
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            g[v].PB(u);
            dg[u]++;
        }
        for (int i = 0; i <= n + m; ++i) Q[i].clear();
        Q[0].PB(n);
        for (int i = 0; i <= n + m; ++i) {
            for (int j = 0; j < Q[i].size(); ++j) {
                u = Q[i][j];
                if (vis[u]) continue;
                d[u] = i;
                for (int k = 0; k < g[u].size(); ++k) {
                    v = g[u][k];
                    --dg[v];
                    Q[dg[v] + d[u] + 1].PB(v);
                }
                vis[u] = 1;
            }
        }
        printf("%d\n", d[1]);
    }
    return 0;
}

/*
2 1
1 2

4 4
1 2
1 4
2 4
1 4

5 7
1 2
2 3
3 5
1 4
4 3
4 5
3 1
*/