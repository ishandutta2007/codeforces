#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 300 + 5;

int n, a[N][N];
int dp[2*N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];

    for (int i = 0; i <= 2*n; i++) for (int j = 0; j <= n; j++) for (int k = 0; k <= n; k++) dp[i][j][k] = INT_MIN;
    dp[2][1][1] = a[1][1];

    for (int d = 3; d <= 2*n; d++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d - i > n or d - j > n or d - i <= 0 or d - j <= 0) continue;
                dp[d][i][j] = max({dp[d - 1][i][j], dp[d - 1][i - 1][j], dp[d - 1][i - 1][j - 1], dp[d - 1][i][j - 1]});
                if (i == j)
                    dp[d][i][j] += a[i][d - i];
                else dp[d][i][j] += a[i][d - i] + a[j][d - j];
            }
        }
    }

    cout << dp[2*n][n][n] << "\n";
    return 0;
}