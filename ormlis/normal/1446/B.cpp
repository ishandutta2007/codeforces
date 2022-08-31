#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            int x = dp[i - 1][j] - 1;
            int y = dp[i][j - 1] - 1;
            dp[i][j] = max(0, max(x, y));
            if (a[i - 1] == b[j - 1]) {
                int z = dp[i - 1][j - 1] + 2;
                dp[i][j] = max(dp[i][j], z);
            }
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}