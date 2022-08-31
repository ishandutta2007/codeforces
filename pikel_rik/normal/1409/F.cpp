#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 200 + 5;

int n, k;
string s, t;

int dp[N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> s >> t;
    s = ' ' + s;

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int c = 0; c < i; c++) {
            for (int j = 0; j <= k; j++) {
                if (t.back() != t.front()) {
                    bool f = t.back() != s[i];
                    if (dp[i - 1][c][j] != -1 and j + f <= k) {
                        dp[i][c][j + f] = max(dp[i][c][j + f], c + dp[i - 1][c][j]);
                        ans = max(ans, dp[i][c][j + f]);
                    }
                    f = t.front() != s[i];
                    if (dp[i - 1][c][j] != -1 and j + f <= k) {
                        dp[i][c + 1][j + f] = max(dp[i][c + 1][j + f], dp[i - 1][c][j]);
                    }
                    if (dp[i - 1][c][j] != -1 and s[i] != t.back() and s[i] != t.front()) {
                        dp[i][c][j] = max(dp[i][c][j], dp[i - 1][c][j]);
                    }
                } else {
                    bool f = s[i] != t.back();
                    if (dp[i - 1][c][j] != -1 and j + f <= k) {
                        dp[i][c + 1][j + f] = max(dp[i][c + 1][j + f], c + dp[i - 1][c][j]);
                        ans = max(ans, dp[i][c + 1][j + f]);
                    }
                    if (dp[i - 1][c][j] != -1 and s[i] != t.back()) {
                        dp[i][c][j] = max(dp[i][c][j], dp[i - 1][c][j]);
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}