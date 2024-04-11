#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, K, a[205], dp[205][205][1005], sum1[1005];

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    sort(a, a + N);
    int sum = 0;
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    for (int n = 2; n <= N; n++) {
        for (int p = 0; p <= N; p++ ){
            for (int k = 0; k <= K; k++) {
                long long diff = a[n - 1] - a[n - 2];
                if (p >= 1 && (long long)k - diff * (p - 1) >= 0) dp[n][p][k] += ((long long)dp[n - 1][p - 1][k - diff * (p - 1)] * (p)) % MOD;
                dp[n][p][k] %= MOD;
//printf("%d\n", dp[n][p][k]);
                if ((long long)k - diff * (p) >= 0) dp[n][p][k] += ((long long)dp[n - 1][p][k - diff * (p)] * (p + 1)) % MOD;
                dp[n][p][k] %= MOD;

                if (p < N && (long long)k - diff * (p + 1) >= 0) dp[n][p][k] += ((long long)dp[n - 1][p + 1][k - diff * (p + 1)]) % MOD;
                dp[n][p][k] %= MOD;

                //printf("%d %d %d = %d\n", n, p, k, dp[n][p][k]);
            }
        }
    }
    for (int i = 0; i <= K; i++) {
        sum += dp[N][0][i];
        sum %= MOD;
    }
    printf("%d\n", sum);
}