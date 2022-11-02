#include <cstdio>

using namespace std;
const int N = 2e3;

int a[5][N], pos[5][N], f[N];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) for (int j = 1; j <= n; j++)
    {
        scanf("%d", &a[i][j]);
        pos[i][a[i][j]] = j;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            bool ok = true;
            for (int o = 1; o < k; o++) if (pos[o][a[0][j]] > pos[o][a[0][i]]) ok = false;
            if (!ok) continue;
            if (f[j] + 1 > f[i]) f[i] = f[j] + 1;
        }
        if (f[i] > ans) ans = f[i];
    }
    printf("%d\n", ans);
    return 0;
}