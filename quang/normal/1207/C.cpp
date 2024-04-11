#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const long long INF = (1ll << 60);

int n, a, b;
char s[N];
long long dp[2][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b;
        cin >> (s + 1);
        dp[0][0] = b;
        dp[1][0] = a + b;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                dp[0][i] = b + a + min(dp[0][i - 1], dp[1][i - 1] + a);
                dp[1][i] = b * 2 + a + min(dp[0][i - 1] + a, dp[1][i - 1]);
            } else {
                dp[0][i] = INF;
                dp[1][i] = dp[1][i - 1] + a + b * 2;
            }
        }
        cout << min(dp[0][n], dp[1][n] + a) << '\n';
    }
    return 0;
}