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

int n, m, c0, d0, a[11], b[11], c[11], d[11];

int dp[11][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> c0 >> d0;
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    for (int i = 0; i <= n; i++) {
        if (i - c0 >= 0)
            dp[0][i] = d0 + dp[0][i - c0];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i-1][j];
            for (int k = 1; k <= a[i] / b[i] && j >= k * c[i]; k++) {
                dp[i][j] = max(dp[i][j], k * d[i] + dp[i-1][j - k * c[i]]);
            }
        }
    }

    cout << dp[m][n] << "\n";
    return 0;
}