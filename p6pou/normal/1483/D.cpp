#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int MAX_N = 600 + 5;
const i64 INF64 = 1e18;

int N, M, Q, ans;
i64 w[MAX_N][MAX_N], d[MAX_N][MAX_N], q[MAX_N][MAX_N];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            w[i][j] = INF64;
            d[i][j] = INF64;
            q[i][j] = INF64;
        }
        d[i][i] = 0;
    }
    for (int i = 1; i <= M; i ++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        w[x][y] = min(w[x][y], (i64)z);
        d[x][y] = min(d[x][y], (i64)z);
        swap(x, y);
        w[x][y] = min(w[x][y], (i64)z);
        d[x][y] = min(d[x][y], (i64)z);
    }
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i ++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        q[x][y] = min(q[x][y], (i64)z);
        swap(x, y);
        q[x][y] = min(q[x][y], (i64)z);
    }
    for (int k = 1; k <= N; k ++) {
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= N; j ++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int x = 1; x <= N; x ++) {
        for (int v = 1; v <= N; v ++) {
            i64 f = -INF64;
            for (int u = 1; u <= N; u ++) {
                if (q[v][u] != INF64) {
                    // printf("x=%d, v=%d, u=%d\n", x, v, u);
                    f = max(f, q[v][u] - d[x][u] - d[x][v]);
                }
            }
            // printf("x=%d, v=%d, f=%lld\n", x, v, f);
            for (int y = 1; y <= N; y ++) {
                if (w[x][y] != INF64) {
                    i64 g = w[x][y] + d[v][y] - d[v][x];
                    if (g <= f) {
                        w[x][y] = w[y][x] = INF64;
                        // printf("useful: x=%d,y=%d\n", x, y);
                        ans ++;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}