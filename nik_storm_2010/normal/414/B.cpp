#include <cstdio>

using namespace std;
const int md = 1000000000 + 7;
const int l = 2000 + 10;

int del[l][l], f[l][l], leng[l];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int o = 1;
        while (o * o <= i)
        {
            if (i % o == 0)
            {
                del[i][leng[i]++] = o;
                int x = i / o;
                if (x != o) del[i][leng[i]++] = x;
            }
            o++;
        }
    }
    f[0][1] = 1;
    for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++)
    {
        f[i][j] = 0;
        for (int x = 0; x < leng[j]; x++)
        {
            f[i][j] += f[i - 1][del[j][x]];
            if (f[i][j] >= md) f[i][j] -= md;
        }
    }
    int ans = 0;
    for (int j = 1; j <= n; j++)
    {
        ans += f[k][j];
        if (ans >= md) ans -= md;
    }
    printf("%d\n", ans);
    return 0;
}