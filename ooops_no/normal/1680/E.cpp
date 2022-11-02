#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int INF = 1e9;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> dp(2, vector<int>(2, INF)), a(2, vector<int>(n));
        vector<int> cnt(n + 1);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                if (c == '*') {
                    a[i][j] = 1;
                } else {
                    a[i][j] = 0;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            cnt[i] = cnt[i + 1];
            if (a[0][i] || a[1][i]) {
                cnt[i]++;
            }
        }
        if (cnt[0] == 0) {
            cout << 0 << endl;
            continue;
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> dpp(2, vector<int>(2, INF));
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    dp[j | a[0][i]][k | a[1][i]] = min(dp[j | a[0][i]][k | a[1][i]], dp[j][k]);
                }
            }
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if ((a[0][i] == 1 && j == 0) || (a[1][i] == 1 && k == 0)) {
                        dp[j][k] = INF;
                    }
                }
            }
            if (cnt[i + 1] == 0) {
                int ans = INF;
                cout << min({dp[1][0], dp[0][1], dp[1][1] + 1}) << endl;
                break;
            }
            dpp[1][1] = dp[1][1] + 2;
            dpp[0][1] = min(dp[0][1] + 1, dp[1][1] + 2);
            dpp[1][0] = min(dp[1][0] + 1, dp[1][1] + 2);
            dpp[0][0] = dp[0][0];
            swap(dp, dpp);
        }
    }
    return 0;
}