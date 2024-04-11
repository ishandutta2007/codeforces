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
const int N = 200 + 5;

int n1, n2, n3, a[N], b[N], c[N];
ll dp[N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n1 >> n2 >> n3;
    for (int i = 1; i <= n1; i++) cin >> a[i];
    for (int i = 1; i <= n2; i++) cin >> b[i];
    for (int i = 1; i <= n3; i++) cin >> c[i];

    sort(a + 1, a + n1 + 1);
    sort(b + 1, b + n2 + 1);
    sort(c + 1, c + n3 + 1);

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]);
            dp[i][j][0] = max(dp[i][j][0], a[i] * b[j] + dp[i - 1][j - 1][0]);
        }
    }

    for (int i = 1; i <= n1; i++) {
        for (int k = 1; k <= n3; k++) {
            dp[i][0][k] = max(dp[i - 1][0][k], dp[i][0][k - 1]);
            dp[i][0][k] = max(dp[i][0][k], a[i] * c[k] + dp[i - 1][0][k - 1]);
        }
    }

    for (int j = 1; j <= n2; j++) {
        for (int k = 1; k <= n3; k++) {
            dp[0][j][k] = max(dp[0][j - 1][k], dp[0][j][k - 1]);
            dp[0][j][k] = max(dp[0][j][k], b[j] * c[k] + dp[0][j - 1][k - 1]);
        }
    }

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            for (int k = 1; k <= n3; k++) {
                dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                dp[i][j][k] = max(dp[i][j][k], a[i] * b[j] + dp[i - 1][j - 1][k]);
                dp[i][j][k] = max(dp[i][j][k], a[i] * c[k] + dp[i - 1][j][k - 1]);
                dp[i][j][k] = max(dp[i][j][k], b[j] * c[k] + dp[i][j - 1][k - 1]);
            }
        }
    }

    cout << dp[n1][n2][n3] << "\n";
    return 0;
}