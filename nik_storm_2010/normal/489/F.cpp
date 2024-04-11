#include <cstdio>

using namespace std;
const int N = 5e2 + 10;

int f[N][N], fresh[N][N], c[N][3], cnt[N];
char s[N];

int main() {
    int n, m, mod;
    scanf("%d %d %d", &n, &m, &mod);
    for (int i = 0; i < N; i++) c[i][0] = 1;
    for (int i = 1; i < N; i++) for (int j = 1; j < 3; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    for (int i = 1; i <= m; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) cnt[j] += (s[j] == '1');
    }
    int lim = n - m;
    f[0][lim] = 1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 2) continue;
        for (int k1 = 0; k1 <= lim; k1++) for (int k2 = 0; k2 <= lim; k2++) fresh[k1][k2] = 0;
        for (int k1 = 0; k1 <= lim; k1++) for (int k2 = 0; k2 <= lim; k2++) {
            if (f[k1][k2] == 0) continue;
            if (cnt[i] == 1) {
                if (k2 >= 1) fresh[k1 + 1][k2 - 1] = (fresh[k1 + 1][k2 - 1] + 1LL * f[k1][k2] * c[k2][1]) % mod;
                if (k1 >= 1) fresh[k1 - 1][k2] = (fresh[k1 - 1][k2] + 1LL * f[k1][k2] * c[k1][1]) % mod;
            }
            else {
                if (k2 >= 2) fresh[k1 + 2][k2 - 2] = (fresh[k1 + 2][k2 - 2] + 1LL * f[k1][k2] * c[k2][2]) % mod;
                if (k2 >= 1 && k1 >= 1) fresh[k1][k2 - 1] = (fresh[k1][k2 - 1] + ((1LL * f[k1][k2] * c[k2][1]) % mod) * c[k1][1]) % mod;
                if (k1 >= 2) fresh[k1 - 2][k2] = (fresh[k1 - 2][k2] + 1LL * f[k1][k2] * c[k1][2]) % mod;
            }
        }
        for (int k1 = 0; k1 <= lim; k1++) for (int k2 = 0; k2 <= lim; k2++) f[k1][k2] = fresh[k1][k2];

    }
    printf("%d\n", f[0][0]);
    return 0;
}