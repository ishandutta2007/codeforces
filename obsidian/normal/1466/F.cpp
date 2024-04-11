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

int f[V], id[V];
int fd(int x) {
    if (f[x] != x) f[x] = fd(f[x]);
    return f[x];
}

bool U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px == py) return false;
    f[px] = py;
    if (id[py] == -1) id[py] = id[px];
    return true;
}

int ans[V], n, m, x, y, z;
int main() {
    while (~scanf("%d%d", &m, &n)) {
        for (int i = 0; i <= n; ++i) f[i] = i, id[i] = -1;
        LL way = 1;
        int K = 0;
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &x);
            /*
            if (x == 1) {
                scanf("%d", &y);
                id[y] = i;
            } else {
                scanf("%d%d", &y, &z);
                int res = U(y, z);
                if (res) {
                    ans[K++] = i;
                    way = 2 * way % P;
                }
            }*/

            if (x == 1) {
                scanf("%d", &y); z = 0;
            } else {
                scanf("%d%d", &y, &z);
            }
            int res = U(y, z);
            if (res) {
                ans[K++] = i;
                way = 2 * way % P;
            }
        }
        /*
        for (int i = 1; i <= n; ++i) if (f[i] == i && id[i] != -1) {
            ans[K++] = id[i];
            way = 2 * way % P;
        }*/
        sort(ans, ans + K);
        printf("%I64d %d\n", way, K);
        for (int i = 0; i < K; ++i) printf("%d ", ans[i]); puts("");
    }
    return 0;
}

/*
3 2
1 1
1 2
2 2 1
2 3
2 1 3
2 1 2
3 5
2 1 2
1 3
1 4
*/