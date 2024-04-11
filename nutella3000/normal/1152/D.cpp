#include <bits/stdc++.h>

using namespace std;
#define int long long
#define loop1(from, n) for(int i = from; i < n;i++)
#define loop2(from, n) for(int i = from;i >= n;i--)
const int inf = 1e9 + 7;

int32_t main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int dp1[n + 1][n + 1];
    int dp2[n + 1][n + 1];
    for(int j = 0;j <= n;j++) {
        dp1[0][j] = 0;
        dp2[0][j] = 0;
    }
    int mod = inf;
    for(int i = 1;i <= n;i++) {
        for(int j = n;j >= 0;j--) {
            if (j > i) {
                dp1[i][j] = 0;
                dp2[i][j] = 0;
                continue;
            }
            if (j == 0) {
                dp1[i][j] = 1 + dp2[i][j + 1];
                dp2[i][j] = dp1[i][j + 1];
            }else if (j == i) {
                dp1[i][j] = 1 + dp2[i - 1][j - 1];
                dp2[i][j] = dp1[i - 1][j - 1];
            }else {
                dp1[i][j] = 1 + max(dp2[i - 1][j - 1] + dp1[i][j + 1], dp1[i - 1][j - 1] + dp2[i][j + 1]);
                dp2[i][j] = dp1[i - 1][j - 1] + dp1[i][j + 1];
            }
            dp1[i][j] %= mod;
            dp2[i][j] %= mod;
        }
    }
    cout << dp1[n][0];
}