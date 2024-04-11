#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(2));

        if (s[0] == '0') {
            dp[0][0] = 0;
            dp[0][1] = 1;
        }
        else {
            dp[0][0] = 1;
            dp[0][1] = 0;
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = 1 + dp[i-1][1];
            }
            else {
                dp[i][0] = 1 + dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
        }

        int best = min(dp[n-1][0], dp[n-1][1]);
        for (int i = 0; i < n - 1; i++) {
            best = min(best, dp[i][0] + dp[n-1][1] - dp[i][1]);
            best = min(best, dp[i][1] + dp[n-1][0] - dp[i][0]);
        }

        cout << best << "\n";
    }
    return 0;
}