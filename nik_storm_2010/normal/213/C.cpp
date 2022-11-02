#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 300 + 10;
const int INF = 2e9;

int f[2 * N][N][N], a[N][N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= 2 * n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) f[i][j][k] = -INF;
    f[2][1][1] = a[1][1];
    for (int i = 2; i < 2 * n; i++) for (int x1 = 1; x1 <= n; x1++) for (int x2 = 1; x2 <= n; x2++)
    {
        if (f[i][x1][x2] == -INF) continue;
        int y1 = i - x1, y2 = i - x2;
        if (1 <= y1 && y1 <= n && 1 <= y2 && y2 <= n); else continue;
        if (x1 != n && y2 != n)
        {
            int add = (x1 + 1 == x2 && y1 == y2 + 1) ? a[x1 + 1][y1] : a[x1 + 1][y1] + a[x2][y2 + 1];
            f[i + 1][x1 + 1][x2] = max(f[i + 1][x1 + 1][x2], f[i][x1][x2] + add);
        }
        if (x1 != n && x2 != n)
        {
            int add = (x1 + 1 == x2 + 1 && y1 == y2) ? a[x1 + 1][y1] : a[x1 + 1][y1] + a[x2 + 1][y2];
            f[i + 1][x1 + 1][x2 + 1] = max(f[i + 1][x1 + 1][x2 + 1], f[i][x1][x2] + add);
        }
        if (y1 != n && y2 != n)
        {
            int add = (x1 == x2 && y1 + 1 == y2 + 1) ? a[x1][y1 + 1] : a[x1][y1 + 1] + a[x2][y2 + 1];
            f[i + 1][x1][x2] = max(f[i + 1][x1][x2], f[i][x1][x2] + add);
        }
        if (y1 != n && x2 != n)
        {
            int add = (x1 == x2 + 1 && y1 + 1 == y2) ? a[x1][y1 + 1] : a[x1][y1 + 1] + a[x2 + 1][y2];
            f[i + 1][x1][x2 + 1] = max(f[i + 1][x1][x2 + 1], f[i][x1][x2] + add);
        }
    }
    printf("%d\n", f[n + n][n][n]);
    return 0;
}