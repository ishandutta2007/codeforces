#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = 998244353;
const int MAXN = (int) 2000;

int dp[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, m, k, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    dp[1][0] = m;
    for(i = 2; i <= n; i++) {
        for(j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j > 0)
                dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j - 1] * (m - 1)) % MOD;
        }
    }
    cout << dp[n][k];
    //cin.close();
    //cout.close();
    return 0;
}