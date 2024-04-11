#include <cstring>
#include <iostream>
using namespace std;

const int A_MAX = 200;
const int MOD = 998244353;

int N;
int dp[A_MAX + 1][2], next_dp[A_MAX + 1][2];

void mod_add(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

int main() {
    scanf("%d", &N);
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;

    for (int i = 0; i < N; i++) {
        memset(next_dp, 0, sizeof(next_dp));
        int A;
        scanf("%d", &A);

        if (A == -1) {
            int less_sum = (dp[0][0] + dp[0][1]) % MOD;
            int greater_equal_sum = 0;

            for (int p = 1; p <= A_MAX; p++)
                mod_add(greater_equal_sum, dp[p][1]);

            for (int a = 1; a <= A_MAX; a++) {
                mod_add(greater_equal_sum, dp[a][0]);
                mod_add(next_dp[a][0], less_sum);
                mod_add(next_dp[a][1], greater_equal_sum);
                mod_add(less_sum, dp[a][0]);
                mod_add(less_sum, dp[a][1]);
                mod_add(greater_equal_sum, MOD - dp[a][0]);
                mod_add(greater_equal_sum, MOD - dp[a][1]);
            }
        } else {
            for (int g = 0; g <= 1; g++)
                for (int p = 0; p <= (g == 1 ? A_MAX : A); p++)
                    mod_add(next_dp[A][p >= A], dp[p][g]);
        }

        memcpy(dp, next_dp, sizeof(dp));
    }

    int answer = 0;

    for (int a = 1; a <= A_MAX; a++)
        mod_add(answer, dp[a][1]);

    printf("%d\n", answer);
}