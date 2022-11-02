#include <cstdio>

using namespace std;
const int MOD = 1e9 + 7;
const int N = 2;

void multi(int a[N][N], int b[N][N], int c[N][N])
{
    int res[N][N];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    {
        res[i][j] = 0;
        for (int k = 0; k < N; k++) res[i][j] = (res[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) c[i][j] = res[i][j];
}

void power(int a[N][N], int step, int b[N][N])
{
    if (step == 1)
    {
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) b[i][j] = a[i][j];
        return;
    }
    int c[N][N];
    power(a, step >> 1, c);
    multi(c, c, b);
    if (step % 2) multi(b, a, b);
}

int main()
{
    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);
    if (x < 0) x += MOD;
    if (y < 0) y += MOD;
    if (n <= 2)
    {
        if (n == 1) printf("%d\n", x); else printf("%d\n", y);
        return 0;
    }
    int a[N][N], b[N][N];
    a[0][0] = 0, a[1][0] = 1, a[0][1] = MOD - 1, a[1][1] = 1;
    power(a, n - 2, b);
    int ans = (1LL * b[0][1] * x+ 1LL * b[1][1] * y) % MOD;
    printf("%d\n", ans);
    return 0;
}