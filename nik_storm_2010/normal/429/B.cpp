#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 2000;

ll f1[N][N], f2[N][N], f3[N][N], f4[N][N], a[N][N];

int main()
{
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    memset(f3, 0, sizeof(f3));
    memset(f4, 0, sizeof(f4));
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f1[i][j] = max(f1[i - 1][j], f1[i][j - 1]) + a[i][j];
    for (int i = 1; i <= n; i++) for (int j = m; j >= 1; j--) f2[i][j] = max(f2[i - 1][j], f2[i][j + 1]) + a[i][j];
    for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) f3[i][j] = max(f3[i + 1][j], f3[i][j + 1]) + a[i][j];
    for (int i = n; i >= 1; i--) for (int j = 1; j <= m; j++) f4[i][j] = max(f4[i + 1][j], f4[i][j - 1]) + a[i][j];
    ll ans = 0;
    for (int i = 2; i < n; i++) for (int j = 2; j < m; j++)
    {
        ans = max(ans, f1[i - 1][j] + f4[i][j - 1] + f2[i][j + 1] + f3[i + 1][j]);
        ans = max(ans, f1[i][j - 1] + f4[i + 1][j] + f2[i - 1][j] + f3[i][j + 1]);
    }
    printf("%I64d\n", ans);
    return 0;
}