#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
const int N = 200;

int a[N][N], b[N][N], c[N][N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
    {
        if (n % i != 0) continue;
        int j = n / i;
        if (__builtin_popcount(j) != 1) continue;
        for (int x = 1; x <= i; x++) for (int y = 1; y <= m; y++) b[x][y] = a[x][y], c[i - x + 1][y] = a[x][y];
        bool good = true;
        for (int o = 1; o <= j; o++)
        {
            int l = (o - 1) * i;
            if (o % 2 == 1)
            {
                for (int x = 1; x <= i; x++) for (int y = 1; y <= m; y++) if (a[l + x][y] != b[x][y]) good = false;
            }
            else
            {
                for (int x = 1; x <= i; x++) for (int y = 1; y <= m; y++) if (a[l + x][y] != c[x][y]) good = false;
            }
        }
        if (good)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}