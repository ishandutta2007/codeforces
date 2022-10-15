#include <cstdio>

const int md = 1000000007;

void add(int & a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int dp[55][111][55][111];
int C[222][222];
const int INF = 1 << 20;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < 222; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= INF) C[i][j] = INF;
        }
    }
    int ans = 0;
    for (int i = 1; 2 * i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            for (int ls = 1; ls <= i; ls++) {
                int bef = i - ls;
                if (bef == 0) dp[i][j][ls][1] = 1; else {
                    for (int z = 1; z <= k; z++) {
                        for (int pre = 1; pre <= bef; pre++) {
                            int val = dp[bef][j - 1][pre][z];
                            int nz = C[ls + pre - 1][pre - 1] * z;
                            if (nz > k) break;
                            if (val == 0) continue;
                            add(dp[i][j][ls][nz], val);
                        }
                    }
                }
                for (int z = 1; z <= k; z++) {
                    add(ans, dp[i][j][ls][z]);
                }
            }
        }
    }
    printf("%d\n", ans);
}