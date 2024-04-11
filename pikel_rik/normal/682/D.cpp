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

int n, m, k, dp[1001][1001][11][2];
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;
    cin >> s >> t;

    for (int l = 1; l <= k; l++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j][l][1] = 1 + max(dp[i - 1][j - 1][l][1], dp[i - 1][j - 1][l - 1][0]);
                dp[i][j][l][0] = max({dp[i - 1][j][l][1], dp[i - 1][j][l][0], dp[i][j - 1][l][1], dp[i][j - 1][l][0]});
            }
        }
    }

    int best = 0;
    for (int l = 1; l <= k; l++) {
        best = max(best, max(dp[n][m][l][0], dp[n][m][l][1]));
    }

    cout << best << "\n";
    return 0;
}