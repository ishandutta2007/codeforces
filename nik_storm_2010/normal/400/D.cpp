#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
const int N = 2e5;
const int K = 500 + 10;
const int INF = 1e9;

int g[K][K], used[N], degree[N], p[N];

int find_parent(int x)
{
    if (p[x] != x) p[x] = find_parent(p[x]);
    return p[x];
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int free = 0;
    for (int i = 1; i <= k; i++)
    {
        int x;
        scanf("%d", &x);
        while (x != 0) used[++free] = i, x--;
    }
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++) g[i][j] = INF;
    for (int i = 1; i <= k; i++) g[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        if (v == 0)
        {
            int px = find_parent(x), py = find_parent(y);
            if (px != py)
            {
                if (degree[px] < degree[py]) swap(px, py);
                p[py] = px;
            }
        }
        g[used[x]][used[y]] = g[used[y]][used[x]] = min(g[used[x]][used[y]], v);
    }
    int i = 1;
    while (i <= n)
    {
        int j = i;
        while (used[i] == used[j] && j <= n) j++;
        int need = find_parent(i);
        i++;
        while (i != j)
        {
            if (find_parent(i) != need)
            {
                puts("No");
                return 0;
            }
            i++;
        }
    }
    for (int o = 1; o <= k; o++) for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++) g[i][j] = min(g[i][j], g[i][o] + g[o][j]);
    puts("Yes");
    for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++)
    {
        if (g[i][j] == INF) g[i][j] = -1;
        printf("%d", g[i][j]);
        if (j == k) printf("\n"); else printf(" ");
    }
    return 0;
}