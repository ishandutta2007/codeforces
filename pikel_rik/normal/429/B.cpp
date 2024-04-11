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
const int N = 1e3 + 5;

int n, m, a[N][N];
ll dp[4][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[0][i][j] = a[i][j] + max(dp[0][i - 1][j], dp[0][i][j - 1]);
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            dp[1][i][j] = a[i][j] + max(dp[1][i + 1][j], dp[1][i][j + 1]);
        }
    }

    //n, 1 => 1, m
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            dp[2][i][j] = a[i][j] + max(dp[2][i][j - 1], dp[2][i + 1][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            dp[3][i][j] = a[i][j] + max(dp[3][i][j + 1], dp[3][i - 1][j]);
        }
    }

    ll best = 0;
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            best = max(best, dp[0][i - 1][j] + dp[1][i + 1][j] + dp[2][i][j - 1] + dp[3][i][j + 1]);
            best = max(best, dp[0][i][j - 1] + dp[1][i][j + 1] + dp[2][i + 1][j] + dp[3][i - 1][j]);
        }
    }

    cout << best << "\n";
    return 0;
}