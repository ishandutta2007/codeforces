#include <cstdio>

using namespace std;
typedef short int si;
const int INF = 32000;
const int N = 100 + 5;
const int P = 17;

int mask[N], res[N];
si f[N][1 << P], go[N][1 << P], a[N], p[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int cnt = 0;
    for (int i = 2; ; i++)
    {
        bool ok = true;
        for (int j = 2; j * j <= i; j++) if (i % j == 0) ok = false;
        if (!ok) continue;
        p[cnt++] = i;
        if (cnt == P) break;
    }
    for (int i = 1; i < N; i++) for (int j = 0; j < P; j++) if (i % p[j] == 0) mask[i] |= (1 << j);
    for (int i = 0; i <= n; i++) for (int j = 0; j < (1 << P); j++) f[i][j] = INF;
    f[0][0] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < (1 << P); j++)
    {
        if (f[i][j] == INF) continue;
        for (int k = 1; k <= a[i + 1]; k++) if ((j & mask[k]) == 0 && f[i + 1][j | mask[k]] > f[i][j] + a[i + 1] - k)
        {
            f[i + 1][j | mask[k]] = f[i][j] + a[i + 1] - k;
            go[i + 1][j | mask[k]] = k;
        }
        for (int k = a[i + 1] + 1; k < 60; k++) if ((j & mask[k]) == 0 && f[i + 1][j | mask[k]] > f[i][j] + k - a[i + 1])
        {
            f[i + 1][j | mask[k]]  =f[i][j] + k - a[i + 1];
            go[i + 1][j | mask[k]] = k;
        }
    }
    int ans = INF, nom;
    for (int j = 0; j < (1 << P); j++) if (f[n][j] < ans) ans = f[n][j], nom = j;
    for (int i = n; i > 0; i--)
    {
        res[i] = go[i][nom];
        nom = nom ^ mask[go[i][nom]];
    }
    for (int i = 1; i <= n; i++) printf("%d ", res[i]);
    return 0;
}