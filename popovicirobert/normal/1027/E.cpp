#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = 998244353;
const int MAXN = 500;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int dp[MAXN + 1][MAXN + 1];
int dp1[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, j;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    dp[0][0] = 1;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            for(int p = i - 1; p >= 0; p--) {
                if(i - p > j) {
                    break;
                }
                if(i - p == j) {
                    for(int a = 0; a <= j; a++) {
                        dp[i][j] += dp[p][a];
                        mod(dp[i][j]);
                    }
                }
                else {
                    dp[i][j] += dp[p][j];
                    mod(dp[i][j]);
                }
            }
        }
    }
    if(k == 1) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    for(int len = 1; len <= min(n, k - 1); len++) {
        int mx = (k + len - 1) / len;
        dp1[0] = 1;
        for(i = 1; i <= n; i++) {
            dp1[i] = 0;
            for(j = i - 1; j >= max(0, i - mx + 1); j--) {
                dp1[i] += dp1[j];
                mod(dp1[i]);
            }
        }
        ans = (ans + 1LL * dp1[n] * dp[n][len]) % MOD;
    }
    ans *= 2;
    mod(ans);
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}