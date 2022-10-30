#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 200 + 5;

double f[N][N][2 * N + 1], p[N];
int a[N];

int main()
{
    int n, l, k;
    scanf("%d %d %d", &n, &l, &k);
    for (int i = 1; i <= n; i++) scanf("%lf", &p[i]), p[i] /= 100;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    f[0][0][N + k] = 1.0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int o = 1; o <= 2 * N; o++)
    {
        if (a[i + 1] == -1)
        {
            f[i + 1][j + 1][o - 1] += f[i][j][o] * p[i + 1];
            f[i + 1][j][o] += f[i][j][o] * (1 - p[i + 1]);
        }
        else
        {
            int all = min(2 * N, o + a[i + 1]);
            f[i + 1][j + 1][all] += f[i][j][o] * p[i + 1];
            f[i + 1][j][o] += f[i][j][o] * (1 - p[i + 1]);
        }
    }
    double ans = 0.0;
    for (int j = l; j <= n; j++) for (int o = N; o <= 2 * N; o++) ans += f[n][j][o];
    printf("%.6lf\n", ans);
    return 0;
}