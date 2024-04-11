#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for (auto &x : b) cin >> x;

        vector<bool> dp(n + 1, false);
        dp[n] = true;

        vector<bool> optimizer(2 * n + 1, false);
        for (int i = n - 1; i >= 0; i--) {
            if (i + b[i] < n) {
                dp[i] = dp[i] || dp[i + b[i] + 1];
            }
            int j = 1 + n - (i + 1);
            dp[i] = dp[i] || optimizer[j];
            if (dp[i + 1] && b[i] + n - i <= 2 * n) {
                optimizer[b[i] + n - i] = true;
            }
        }

        cout << (dp.front() ? "YES" : "NO") << '\n';
    }
    return 0;
}