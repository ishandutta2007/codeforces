#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 1e9;

char s[N];
int n;
int dp[N][2][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> (s + 1);
        n = strlen(s + 1);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }
        dp[0][0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if (dp[i][j][k] >= INF) continue;
                    bool f = 1;
                    f &= (j == 1 || s[i + 1] != s[i]);
                    if (i > 0) f &= (k == 1 || s[i + 1] != s[i - 1]);
                    dp[i + 1][1][j] = min(dp[i + 1][1][j], dp[i][j][k] + 1);
                    if (f) dp[i + 1][0][j] = min(dp[i + 1][0][j], dp[i][j][k]);
                }
            }
        }
        int res = INF;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res = min(res, dp[n][j][k]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}