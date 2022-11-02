#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
const ll INF = 1e18;

ll f[N][N];
int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) f[i][j] = INF;
    f[0][0] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j <= n; j++)
    {
        if (f[i][j] == INF) continue;
        if (a[i + 1] <= a[j]) f[i + 1][i + 1] = min(f[i + 1][i + 1], f[i][j]); else
        {
            f[i + 1][j] = min(f[i + 1][j], f[i][j] + 1);
            f[i + 1][i + 1] = min(f[i + 1][i + 1], f[i][j] + a[i + 1] - a[j]);
        }
    }
    ll ans = INF;
    for (int i = 0; i <= n; i++) ans = min(ans, f[n][i]);
    printf("%I64d\n", ans);
    return 0;
}