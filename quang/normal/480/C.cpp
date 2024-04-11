#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 5050;
const long long MOD = 1000000007;

int n, a, b, k;
long long dp[N][N];

void Go() {
    for(int j = 1; j <= k; j++) {
        for(int i = 1; i <= n; i++) {
            if(i == b) dp[i][j] == 0;
            else {
                int hieu = abs(b - i) - 1;
                int dau = max(1, i - hieu);
                int cuoi = min(n, i + hieu);
                long long x = (dp[cuoi][j - 1] - dp[dau - 1][j - 1] - (dp[i][j - 1] - dp[i - 1][j - 1]) + MOD + MOD + MOD) % MOD;
                dp[i][j] = x;
            }
        }
        for(int i = 1; i <= n; i++)
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> a >> b >> k;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
    if(i == b) dp[i][0] = 0;
    else dp[i][0] = 1;
    for(int i = 1; i <= n; i++) dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
    Go();
    cout << (1ll * (dp[a][k] - dp[a - 1][k]) + MOD) % MOD;
    return 0;
}