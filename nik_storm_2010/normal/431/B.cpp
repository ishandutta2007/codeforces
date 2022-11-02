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
const int N = 10;

int g[N][N], a[N], used[N], ans, n;

void gen(int x)
{
    if (x > n)
    {
        int cur = 0;
        cur += g[a[1]][a[2]];
        cur += g[a[2]][a[1]] + g[a[2]][a[3]];
        cur += g[a[3]][a[2]] + 2 * g[a[3]][a[4]];
        cur += 2 * g[a[4]][a[3]] + 2 * g[a[4]][a[5]];
        cur += 2 * g[a[5]][a[4]];
        ans = max(ans, cur);
        return;
    }
    for (int i = 1; i <= 5; i++) if (!used[i])
    {
        used[i] = true;
        a[x] = i;
        gen(x + 1);
        used[i] = false;
    }
}

int main()
{
    n = 5;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &g[i][j]);
    ans = 0;
    gen(1);
    printf("%d\n", ans);
    return 0;
}