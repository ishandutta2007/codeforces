#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int INF = 1e9;

int solve2(int n, vector<int> a) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -INF));
    dp[1][0] = 0;
    a.pb(0);
    for (int i = 0; i < n; i++) {
        for (int k = n; k >= 0; k--) {
            int j = i + 1, mx = -INF;
            for (auto to : dp[k]) {
                mx = max(mx, to);
            }
            for (int j = i + 1; j < n; j++) {
                if (j - i <= k) {
                    if (mx != -INF) dp[k - (j - i)][j] = max(dp[k - (j - i)][j], mx);
                }
            }
        }
        vector<vector<int>> new_dp(n + 1, vector<int>(n + 1, -INF));
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < n; k++) {
                new_dp[j][k] = max(new_dp[j][k], dp[j][k] + a[k]);
                if (j + 1 <= n) {
                    if (k <= i) {
                        new_dp[j + 1][i + 1] = max(new_dp[j + 1][i + 1], dp[j][k] + a[k]);
                    } else {
                        new_dp[j + 1][n] = max(new_dp[j + 1][n], dp[j][k] + a[k]);
                    }
                }
            }
        }
        swap(dp, new_dp);
    }
    int mx = 0;
    for (int j = 0; j <= n; j++) {
        for (auto to : dp[j]) {
            mx = max(mx, to);
        }
    }
    return mx;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve2(n, a) << endl;
    return 0;
}