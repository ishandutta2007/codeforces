#include <bits/stdc++.h>

using namespace std;

const int N = 4010;
const int INF = 1e9;

int n;
int a[N];
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n * 2; i++) {
            cin >> a[i];
        }
        a[n * 2 + 1] = INF;
        for (int i = 0; i <= n * 2 + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {
                dp[i][j] = 0;
            }
        }
        dp[n * 2 + 1][0] = INF;
        for (int i = n * 2 + 1; i > 1; i--) {
            for (int j = 0; j <= n; j++) {
                if (dp[i][j] == 0) continue;
                if (a[i - 1] < a[i]) {
                    if (j + 1 <= n) dp[i - 1][j + 1] = max(dp[i - 1][j + 1], dp[i][j]);
                    int num = n * 2 - i + 1 - j + 1;
                    if (num >= 0 && num <= n) {
                        dp[i - 1][num] = max(dp[i - 1][num], a[i]);
                    }
                } else if (a[i - 1] < dp[i][j]) {
                    if (j + 1 <= n) dp[i - 1][j + 1] = max(dp[i - 1][j + 1], dp[i][j]);
                }
            }
        }
        cout << (dp[1][n] > 0 ? "YES" : "NO") << '\n';
    }   
    return 0;
}