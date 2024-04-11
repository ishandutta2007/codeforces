#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 200 + 5;
const int M = 40000 + 5;
const int INF = 2e9;

int f[N][M][2], sum[N], h[N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, a, b;
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + h[i];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) for (int k = 0; k < 2; k++) f[i][j][k] = INF;
    if (a >= h[1]) f[1][a - h[1]][0] = 0;
    if (b >= h[1]) f[1][a][1] = 0;
    for (int i = 1; i < n; i++) for (int j = 0; j <= a; j++) for (int k = 0; k < 2; k++)
    {
        if (f[i][j][k] == INF) continue;
        int o = b - sum[i] - j + a;
        if (j >= h[i + 1])
        {
            int add = (k == 0) ? 0 : min(h[i], h[i + 1]);
            f[i + 1][j - h[i + 1]][0] = min(f[i + 1][j - h[i + 1]][0], f[i][j][k] + add);
        }
        if (o >= h[i + 1])
        {
            int add = (k == 0) ? min(h[i], h[i + 1]) : 0;
            f[i + 1][j][1] = min(f[i + 1][j][1], f[i][j][k] + add);
        }
    }
    int ans = INF;
    for (int j = 0; j <= a; j++) for (int k = 0; k < 2; k++) ans = min(ans, f[n][j][k]);
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}