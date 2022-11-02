#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 5000 + 10;

long long f[N][N], sum[N];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%I64d", &sum[i]);
    for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
    for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) {
        f[i + 1][j] = max(f[i + 1][j], f[i][j]);
        if (j == k || i + m > n) continue;
        f[i + m][j + 1] = max(f[i + m][j + 1], f[i][j] + sum[i + m] - sum[i]);
    }
    printf("%I64d\n", f[n][k]);
    return 0;
}