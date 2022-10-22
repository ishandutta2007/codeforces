#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3, MOD = 998244353;
int dp[MAXN][MAXN];

main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (int i = 0; i < n; ++i) {
        if (i >= m || s[0] == t[i]) {
            dp[i][i + 1] = 2;
        }
    }
    for (int len = 1; len < n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len;
            if (l != 0) {
                if (l - 1 >= m || t[l - 1] == s[len]) {
                    dp[l - 1][r] += dp[l][r];
                    dp[l - 1][r] %= MOD;
                }
            }
            if (r != n) {
                if (r >= m || t[r] == s[len]) {
                    dp[l][r + 1] += dp[l][r];
                    dp[l][r + 1] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i = m; i <= n; ++i) {
        ans += dp[0][i];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}