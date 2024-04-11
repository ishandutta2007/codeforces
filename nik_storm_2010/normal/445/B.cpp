#include <cstdio>

using namespace std;
typedef long long ll;
const int N = 100;

int g[N][N], n, m;
bool used[N];
ll ans;

void dfs(int x, int multi)
{
    if (used[x]) return;
    used[x] = true;
    if (multi) ans *= 2;
    for (int i = 1; i <= n; i++) if (g[x][i]) dfs(i, 1);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][y] = g[y][x] = 1;
    }
    ans = 1;
    for (int i = 1; i <= n; i++) dfs(i, 0);
    printf("%I64d\n", ans);
    return 0;
}