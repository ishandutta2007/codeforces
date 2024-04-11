#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<vector<int>> lcp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                if (i == n - 1 || j == n - 1) {
                    lcp[i][j] = 1;
                } else {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                }
            }
        }
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + a);
        for (int j = 0; j < i; j++) {
            int k = min(lcp[i][j], i - j);
            dp[i + k] = min(dp[i + k], dp[i] + b);
        }
    }
    cout << dp[n] << "\n";

    return 0;
}