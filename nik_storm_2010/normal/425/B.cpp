#include <algorithm>
#include <cstdio>

using namespace std;
const int N = 200;

int a[N][N], b[N], n, m;

int count(int x)
{
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        int k1 = 0, k2 = 0;
        for (int j = 1; j <= x; j++) if (a[i][j] == b[j]) k1++; else k2++;
        cur += min(k1, k2);
    }
    return cur;
}

int main()
{
    int k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    int ans = 0;
    b[1] = 0;
    for (int j = 2; j <= m; j++)
    {
        b[j] = 0;
        int c1 = count(j);
        b[j] = 1;
        int c2 = count(j);
        if (c1 <= c2) b[j] = 0, ans = c1; else b[j] = 1, ans = c2;
    }
    if (ans > k) printf("%d\n", -1); else printf("%d\n", ans);
    return 0;
}