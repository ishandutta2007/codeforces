#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;
const lint MOD = 1e9 + 7;

int grid[2005][2005];
lint dp[2005][2005][2];
lint prefix[2005][2005][2];
// 0 right, 1 down
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char a; cin >> a;
            if (a == 'R') grid[i][j] = 1;
        }
    }

    for (int i = N; i >= 1; i--) {
        for (int j = M; j >= 1; j--) {
            prefix[i][j][0] = prefix[i][j + 1][0] + grid[i][j];
            prefix[i][j][1] = prefix[i + 1][j][1] + grid[i][j];
        }
    }

    if (N == 1 && M == 1) {
        cout << 1 << "\n";
        return 0;
    }

    for (int i = N; i >= 1; i--) {
        for (int j = M; j >= 1; j--) {
            if (i == N && j == M) continue;
            dp[i][j][0] = (dp[i][j + 1][0] + dp[i][j + 1][1]) % MOD;
            dp[i][j][1] = (dp[i + 1][j][0] + dp[i + 1][j][1]) % MOD;
            if (j < M && grid[i][j + 1] == 1) {
                dp[i][j][0] -= dp[i][M - prefix[i][j + 1][0] + 1][1] % MOD;
            }
            if (i < N && grid[i + 1][j] == 1) {
                dp[i][j][1] -= dp[N - prefix[i + 1][j][1] + 1][j][0] % MOD;
            }
            if (i == N) {
                dp[i][j][0] = (prefix[i][j + 1][0] == 0)? 1 : 0;
            }
            if (j == M) {
                dp[i][j][1] = (prefix[i + 1][j][1] == 0)? 1 : 0;
            }
            dp[i][j][0] %= MOD;
            dp[i][j][0] += MOD;
            dp[i][j][0] %= MOD;
            
            dp[i][j][1] %= MOD;
            dp[i][j][1] += MOD;
            dp[i][j][1] %= MOD;
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << dp[i][j][0] + dp[i][j][1] << " ";
    //     }
    //     cout << "\n";
    // }

    lint ans = dp[1][1][0] + dp[1][1][1];
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    cout << ans << "\n";
}