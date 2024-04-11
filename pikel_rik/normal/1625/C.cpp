#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, k;
    cin >> n >> l >> k;

    vector<int> d(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    d[n] = l, a[n] = 0;

    constexpr int inf = INT_MAX;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, inf));
    fill(dp[n].begin(), dp[n].end(), 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            for (int nxt = i + 1; nxt - i - 1 <= j && nxt <= n; nxt++) {
                dp[i][j] = min(dp[i][j], a[i] * (d[nxt] - d[i]) + dp[nxt][j - (nxt - i - 1)]);
            }
        }
    }

    cout << dp[0][k] << '\n';
    return 0;
}