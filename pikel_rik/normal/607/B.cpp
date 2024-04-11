#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 500 + 5;

int n, c[N], dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            if (i > j)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = 1;
            else {
                dp[i][j] = 1 + dp[i + 1][j];
                for (int k = i + 2; k <= j; k++) {
                    if (c[k] == c[i])
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
                }
                if (c[i] == c[i + 1])
                    dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";
    return 0;
}