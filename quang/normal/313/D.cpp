#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1e15
#define N 310

using namespace std;

int n, m, k;
long long a[N][N], b[N][N];

int main()
{
   //fi, fo;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) a[i][j] = b[i][j] = MAX;
    for(int i = 1; i <= m; i++) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        a[l][r] = min(a[l][r], 1ll * c);
    }
    for(int i = 1; i <= n; i++)
    for(int j = i; j <= n; j++)
    if(a[i][j] != MAX)
    for(int u = i; u <= j; u++)
    for(int v = u; v <= j; v++)
        a[u][v] = min(a[u][v], a[i][j]);
    for(int i = 0; i <= n; i++) b[i][0] = 0;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= i; j++) {
        b[i][j] = b[i - 1][j];
        for(int sl = 1; sl <= j; sl++)
        if(a[i - sl + 1][i] < MAX && b[i - sl][j - sl] < MAX)
            b[i][j] = min(b[i][j], b[i - sl][j - sl] + a[i - sl + 1][i]);
    }
    long long res = MAX;
    for(int i = k; i <= n; i++) res = min(res, b[n][i]);
    printf("%I64d", (res < MAX)? res : -1ll);
    return 0;
}