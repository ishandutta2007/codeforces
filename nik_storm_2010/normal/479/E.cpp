#include <cstdio>

using namespace std;
const int MOD = 1e9 + 7;
const int N = 5e3 + 10;

int f[N][N], sum[N][N];

int main() {
    int n, a, b, k;
    scanf("%d %d %d %d", &n, &a, &b, &k);
    if (a > b) a = n - a + 1, b = n - b + 1;
    f[a][0] = 1;
    for (int i = 1; i < b; i++) sum[i][0] = sum[i - 1][0] + f[i][0];
    for (int j = 1; j <= k; j++) for (int i = 1; i < b; i++) {
        int x = (b + i - 1) / 2;
        f[i][j] = sum[x][j - 1] - f[i][j - 1];
        if (f[i][j] < 0) f[i][j] += MOD;
        sum[i][j] = sum[i - 1][j] + f[i][j];
        if (sum[i][j] >= MOD) sum[i][j] -= MOD;
    }
    printf("%d\n", sum[b - 1][k]);
    return 0;
}