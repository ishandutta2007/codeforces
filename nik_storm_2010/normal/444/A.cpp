#include <cstdio>

using namespace std;
const int N = 500 + 50;

int g[N][N], a[N], edges[N];
bool used[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x][y] = g[y][x] = z;
    }
    double ans = 0;
    for (int start = 1; start <= n; start++)
    {
        for (int i = 1; i <= n; i++) used[i] = false, edges[i] = 0;
        int p = a[start], q = 0;
        used[start] = true;
        for (int j = 1; j <= n; j++) if (g[start][j]) edges[j] += g[start][j];
        while (true)
        {
            int nom = 0;
            double cur = 0;
            for (int j = 1; j <= n; j++) if (used[j] == false && edges[j] != 0)
            {
                if (nom == 0)
                {
                    nom = j;
                    cur = (p + a[j] + 0.0) / (q + edges[j]);
                    continue;
                }
                double now = (p + a[j] + 0.0) / (q + edges[j]);
                if (cur < now) cur = now, nom = j;
            }
            if (nom == 0) break;
            used[nom] = true;
            for (int j = 1; j <= n; j++) if (g[nom][j]) edges[j] += g[nom][j];
            p += a[nom];
            q += edges[nom];
            if (ans < cur) ans = cur;
        }
    }
    printf("%.9lf\n", ans);
    return 0;
}