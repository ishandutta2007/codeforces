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
const int P = 998244353;
const int V = 610;
const int oo = 1e9;
int d[V][V];
int ans[V][V];
vector<int> g[V];
int n, m, x, y;

int main() {
    bool DEBUG = false;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = oo;
        for (int i = 1; i <= n; ++i) d[i][i] = 0, g[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x, &y);
            d[x][y] = d[y][x] = 1;
            g[x].PB(y);
            g[y].PB(x);
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        memset(ans, 0, sizeof(ans));
        for (x = 1; x <= n; ++x) {
            for (y = x; y <= n; ++y) {
                bool ok = true;
                int mid = 0;
                int res = 1;
                //DEBUG = (x == 5 && y == 6);
                for (int z = 1; z <= n; ++z) {
                    if (x == z || y == z) continue;
                    if (DEBUG)printf("dz %d %d %d\n", z, d[x][z], d[y][z]);
                    if (d[x][z] + d[y][z] == d[x][y]) ++mid;
                    else if (d[x][z] + d[x][y] == d[y][z]) {
                        int cnt = 0;
                        for (int i = 0; i < g[z].size(); ++i) {
                            int j = g[z][i];
                            if (d[x][j] + 1 == d[x][z]) cnt++;
                        }
                        if (DEBUG)printf("X %d %d\n", z, cnt);
                        res = (LL) res * cnt % P;
                    }
                    else if (d[y][z] + d[x][y] == d[x][z]) {
                        int cnt = 0;
                        for (int i = 0; i < g[z].size(); ++i) {
                            int j = g[z][i];
                            if (d[y][j] + 1 == d[y][z]) cnt++;
                        }
                        if (DEBUG)printf("Y %d %d\n", z, cnt);
                        res = (LL) res * cnt % P;
                    }
                    else {
                        int cnt = 0;
                        for (int i = 0; i < g[z].size(); ++i) {
                            int j = g[z][i];
                            if (d[y][j] + 1 == d[y][z] && d[x][j] + 1 == d[x][z]) cnt++;
                        }
                        if (DEBUG)printf("Z %d %d\n", z, cnt);
                        res = (LL) res * cnt % P;
                    }
                }
                if (DEBUG)printf("%d %d %d %d %d %d\n", x, y, res, d[x][y], mid, ok);
                if ((x != y && mid > d[x][y] - 1) || !ok) continue;
                ans[x][y] = ans[y][x] = res;
            }
        }
        for (int i = 1; i <= n; ++i, puts("")) {
            for (int j = 1; j <= n; ++j) {
                printf("%d ", ans[i][j]);
            }
        }

    }
    return 0;
}

/*
4 4
1 2
2 3
3 4
1 4

8 9
1 2
1 3
1 4
2 7
3 5
3 6
4 8
2 3
3 4
*/