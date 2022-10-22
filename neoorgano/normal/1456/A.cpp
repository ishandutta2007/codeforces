#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5;
int dp[MAXN];

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, p, k;
        cin >> n >> p >> k;
        string s;
        cin >> s;
        int x, y;
        cin >> x >> y;
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i + k <= n) {
                dp[i] = dp[i + k];
            } else {
                dp[i] = 0;
            }
            if (s[i] == '0') {
                dp[i] += x;
            }
        }
        int ans = 1e18;
        for (int z = 0; p + z - 1 < n; ++z) {
            int cur = z * y + dp[p + z - 1];
            ans = min(ans, cur);
        }
        /// ans = min(ans, y * (n - p + 1));
        cout << ans << endl;
    }
    return 0;
}