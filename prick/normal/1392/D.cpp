#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define sz(x) ((int) (x).size())

const int inf = 1e6;

void calc(int n, const vector<int> &arr, vector<vector<vector<int>>> &dp) {
    for (int k = 2; k < n; ++k) {
        for (int a = 0; a < 2; ++a) {
            for (int b = 0; b < 2; ++b) {
                for (int c = 0; c < 2; ++c) {
                    if (a == b && b == c) continue;
                    int add = (c == arr[k]) ? 0: 1;
                    dp[k][b][c] = min(dp[k][b][c], dp[k - 1][a][b] + add);
                }
            }
        }
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = (s[i] == 'L');
    }
    int ans = inf;
    for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
            int add = 0;
            if (arr[0] != a) ++add;
            if (arr[1] != b) ++add;
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, inf)));
            dp[1][a][b] = add;
            calc(n, arr, dp);
            for (int c = 0; c < 2; ++c) {
                for (int d = 0; d < 2; ++d) {
                    if (d == a && a == b) continue;
                    if (c == d && d == a) continue;
                    ans = min(ans, dp[n - 1][c][d]);
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
}