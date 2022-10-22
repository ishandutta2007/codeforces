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
const int V = 30;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int a[V][V], n, m, _;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        vector<PII> g;
        for (int i = 0; i < m; ++i) g.PB({0, i});
        for (int i = 1; i < n; ++i) g.PB({i, m - 1});
        for (int i = m - 2; i >= 0; --i) g.PB({n - 1, i});
        for (int i = n - 2; i > 0; --i) g.PB({i, 0});
        for (int i = 0; i < g.size(); ++i) {
            bool ok = true;
            int x = g[i].fi;
            int y = g[i].se;
            for (int j = 0; j < 8; ++j) {
                int tx = x + dx[j];
                int ty = y + dy[j];
                if (tx < 0 || tx >= n) continue;
                if (ty < 0 || ty >= m) continue;
                //printf("T %d %d\n", tx, ty);
                if (a[tx][ty] == 1) ok = false;
            }
            //printf("G %d %d %d\n", x, y, ok);
            if (ok) a[x][y] = 1;
        }
        for (int i = 0; i < n; ++i, puts("")) for (int j = 0; j < m; ++j) printf("%d", a[i][j]);
    }
    return 0;
}

/*
3
3 5
4 4
5 6
*/