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
const int md = 1000000000 + 7;
const int N = 100 + 5;

int f[N][N][N];

int main()
{
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int big = 0; big <= k; big++)
    {
        if (f[i][j][big] == 0) continue;
        for (int x = 1; x <= big; x++)
        {
            if (j + x > n) break;
            f[i + 1][j + x][big] += f[i][j][big];
            if (f[i + 1][j + x][big] >= md) f[i + 1][j + x][big] -= md;
        }
        for (int x = big + 1; x <= k; x++)
        {
            if (j + x > n) break;
            f[i + 1][j + x][x] += f[i][j][big];
            if (f[i + 1][j + x][x] >= md) f[i + 1][j + x][x] -= md;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) for (int big = d; big <= k; big++)
    {
        ans += f[i][n][big];
        if (ans >= md) ans -= md;
    }
    printf("%d\n", ans);
    return 0;
}