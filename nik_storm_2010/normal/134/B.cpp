#include <cstdio>
#include <algorithm>

using namespace std;

int ans;

void dfs(int x, int y, int sum)
{
    if (y == 1) ans = min(ans, sum + x - 1);
    if (x == 0 || y == 0) return;
    dfs(y, x % y, sum + x / y);
}

int main()
{
    int n;
    scanf("%d", &n);
    ans = 2e9;
    for (int i = 1; i <= n; i++) dfs(n, i, 0);
    printf("%d\n", ans);
    return 0;
}