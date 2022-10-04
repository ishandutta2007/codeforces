// luogu
#include <cstdio>

typedef long long LL;
const int Mod = 998244353;

inline int chk(int x) { if (x < 0) x += Mod; if (x >= Mod) x -= Mod; return x; }

inline int qPow(int b, int e)
{
    int a = 1;
    for (; e; b = (LL)b * b % Mod, e >>= 1)
        if (e & 1) a = (LL)a * b % Mod;
    return a;
}

int p, s, r, c[5105][105];

void Init()
{
    for (int i = 0; i <= 5100; ++i) c[i][0] = 1;
    for (int i = 0; i <= 5100; ++i)
        for (int j = 1; j <= i && j <= 100; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % Mod;
}

inline int Calc(int n, int m, int x)
{
    LL S = 0;
    for (int i = 0; i <= m && i * x <= n; ++i)
    {
        LL s = (LL)c[m][i] * c[n - x * i + m - 1][m - 1] % Mod;
        S += i & 1 ? -s : s;
    }
    return (S % Mod + Mod) % Mod;
}

int Sum1, Sum2;

int main()
{
    scanf("%d%d%d", &p, &s, &r);
    if (p == 1) return puts("1"), 0;
    Init();
    for (int x = r; x <= s; ++x)
    {
        if (x * p < s) continue;
        for (int i = 1; i <= p; ++i)
        {
            if (i * x > s || (p - i) * (x - 1) + i * x < s)
                continue;
            if (i == p) { Sum2 = (Sum2 + (i * x == s ? qPow(i, Mod - 2) : 0)) % Mod; continue; }
            Sum2 = (Sum2 + (LL)c[p - 1][i - 1] * Calc(s - i * x, p - i, x) % Mod * qPow(i, Mod - 2)) % Mod;
        }
    }
    Sum1 = c[s - r + p - 1][p - 1];
    printf("%lld\n", (LL)Sum2 * qPow(Sum1, Mod - 2) % Mod);
    return 0;
}