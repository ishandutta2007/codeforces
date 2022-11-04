#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = 998244353;
const int MAXN = (int) 1e5;
const int MAXVAL = 200;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int dp[2][MAXVAL + 1][2];
int arr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    if(arr[1] == -1) {
        for(i = 1; i <= MAXVAL; i++) {
            dp[1][i][0] = i;
        }
    }
    else {
        for(i = arr[1]; i <= MAXVAL; i++) {
            dp[1][i][0] = 1;
        }
    }
    for(i = 2; i <= n; i++) {
        memset(dp[i & 1], 0, sizeof(dp[i & 1]));
        if(arr[i] == -1) {
            for(j = 1; j <= MAXVAL; j++) {
                dp[i & 1][j][0] += dp[1 - i & 1][j - 1][0];
                mod(dp[i & 1][j][0]);
                dp[i & 1][j][0] += dp[1 - i & 1][j - 1][1];
                mod(dp[i & 1][j][0]);

                if(i > 2) {
                    dp[i & 1][j][1] = (1LL * dp[i & 1][j][1] + dp[1 - i & 1][MAXVAL][1] - dp[1 - i & 1][j - 1][1] + MOD) % MOD;
                }
                dp[i & 1][j][1] = (1LL * dp[i & 1][j][1] + dp[1 - i & 1][j][0] - dp[1 - i & 1][j - 1][0] + MOD) % MOD;
            }
        }
        else {
            j = arr[i];
            dp[i & 1][j][0] += dp[1 - i & 1][j - 1][0];
            mod(dp[i & 1][j][0]);
            dp[i & 1][j][0] += dp[1 - i & 1][j - 1][1];
            mod(dp[i & 1][j][0]);

            if(i > 2) {
                dp[i & 1][j][1] = (1LL * dp[i & 1][j][1] + dp[1 - i & 1][MAXVAL][1] - dp[1 - i & 1][j - 1][1] + MOD) % MOD;
            }
            dp[i & 1][j][1] = (1LL * dp[i & 1][j][1] + dp[1 - i & 1][j][0] - dp[1 - i & 1][j - 1][0] + MOD) % MOD;
        }
        for(j = 1; j <= MAXVAL; j++) {
            dp[i & 1][j][0] += dp[i & 1][j - 1][0];
            mod(dp[i & 1][j][0]);
            dp[i & 1][j][1] += dp[i & 1][j - 1][1];
            mod(dp[i & 1][j][1]);
        }
    }
    int ans;
    if(arr[n] == -1) {
        ans = dp[n & 1][MAXVAL][1];
    }
    else {
        ans = dp[n & 1][arr[n]][1] - dp[n & 1][arr[n] - 1][1] + MOD;
        mod(ans);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}