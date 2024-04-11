#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n, vector<int>(n));

    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) {
                dp[l][r] = 1;
            } else {
                dp[l][r] = 1 + dp[l + 1][r];
                for (int m = l + 1; m <= r; m++) {
                    if (s[l] == s[m]) {
                        dp[l][r] = min(dp[l][r],
                                dp[l + 1][m - 1] + dp[m][r]);
                    }
                }
            }
        }
    }
    cout << dp[0][n - 1] << "\n";

    return 0;
}