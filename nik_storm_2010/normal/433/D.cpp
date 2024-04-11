#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 1000 + 10;

int a[N][N], up[N][N], dn[N][N], lf[N][N], rh[N][N], c[N];

int solve(int x, int n)
{
    int res = 0;
    int l = x, r = x, top = c[x];
    while (true)
    {
        res = max(res, (r - l + 1) * top);
        if (l == 1 && r == n) return res;
        if (l == 1)
        {
            r++, top = min(top, c[r]);
            continue;
        }
        if (r == n)
        {
            l--, top = min(top, c[l]);
            continue;
        }
        if (c[l - 1] >= c[r + 1]) l--, top = min(top, c[l]); else r++, top = min(top, c[r]);
    }
}

int main()
{
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] == 0) up[i][j] = 0; else up[i][j] = up[i - 1][j] + 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] == 0) lf[i][j] = 0; else lf[i][j] = lf[i][j - 1] + 1;
    for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) if (a[i][j] == 0) dn[i][j] = 0; else dn[i][j] = dn[i + 1][j] + 1;
    for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) if (a[i][j] == 0) rh[i][j] = 0; else rh[i][j] = rh[i][j + 1] + 1;
    for (int t = 1; t <= q; t++)
    {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1)
        {
            a[x][y] ^= 1;
            for (int i = x; i <= n; i++) if (a[i][y] == 0) up[i][y] = 0; else up[i][y] = up[i - 1][y] + 1;
            for (int i = x; i >= 1; i--) if (a[i][y] == 0) dn[i][y] = 0; else dn[i][y] = dn[i + 1][y] + 1;
            for (int j = y; j <= m; j++) if (a[x][j] == 0) lf[x][j] = 0; else lf[x][j] = lf[x][j - 1] + 1;
            for (int j = y; j >= 1; j--) if (a[x][j] == 0) rh[x][j] = 0; else rh[x][j] = rh[x][j + 1] + 1;
        }
        else
        {
            int ans = 0;
            for (int i = 1; i <= n; i++) c[i] = lf[i][y];
            ans = max(ans, solve(x, n));
            for (int i = 1; i <= n; i++) c[i] = rh[i][y];
            ans = max(ans, solve(x, n));
            for (int j = 1; j <= m; j++) c[j] = dn[x][j];
            ans = max(ans, solve(y, m));
            for (int j = 1; j <= m; j++) c[j] = up[x][j];
            ans = max(ans, solve(y, m));
            printf("%d\n", ans);
        }
    }
    return 0;
}