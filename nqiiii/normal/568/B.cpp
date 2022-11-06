#include <bits/stdc++.h>
using namespace std;
const int maxN = 4000, mod = 1000000007;
int n, f[maxN + 10], c[maxN + 10][maxN + 10];
int fac[maxN + 10], ans;

void PreWork() {
    c[0][0] = fac[0] = 1;
    for (int i = 1; i <= maxN; ++i) {
        c[i][0] = 1;
        fac[i] = 1ll * fac[i - 1] * i % mod;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
}

int main() {
    PreWork();
    scanf("%d", &n);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j)
            (f[i] += 1ll * f[i - j] * c[i - 1][j - 1] % mod) %= mod;
    }
    for (int i = 1; i <= n; ++i) (ans += 1ll * c[n][i] * f[n - i] % mod) %= mod;
    printf("%d", ans);
}