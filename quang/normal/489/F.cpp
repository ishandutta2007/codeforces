#include <bits/stdc++.h>
#define Task "F"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 550;

int n, m, mod, sl1, sl2, sum;
int a[N];
long long dp[N][N * 3];

int main() {
    ios_base::sync_with_stdio(0);
   // fi;
    cin >> n >> m >> mod;
    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++) {
        char x;
        cin >> x;
        if(x == '1') a[j]++;
    }
    sl1 = sl2 = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) sl1++;
        if(a[i] == 1) sl2++;
    }
    sum = sl1 * 2 + sl2;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= sl1; i++) {
        for(int j = 0; j <= sum; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }
            if(i * 2 + j > sum) break;
            if(i >= 2) dp[i][j] += dp[i - 2][j + 2] * i * (i - 1) / 2;
            if(i >= 1) dp[i][j] += dp[i - 1][j] * i * j;
            if(j >= 2) dp[i][j] += dp[i][j - 2] * j * (j - 1) / 2;
            dp[i][j] %= mod;
        }
    }
    cout << dp[sl1][sl2];
    return 0;
}