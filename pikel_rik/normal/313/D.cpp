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
const int N = 300 + 5;

int n, m, k, a[N][N];
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    fill(a[0], a[n+1], INT_MAX);
    fill(dp[0], dp[n+1], LLONG_MAX);

    for (int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;

        a[l][r] = min(a[l][r], c);
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);

            ll mn = LLONG_MAX;

            for (int l = 1; l <= j; l++) {
                mn = min(mn, dp[i - l][j - l]);
                if (a[i - l + 1][i] == INT_MAX or mn == LLONG_MAX) continue;
                dp[i][j] = min(dp[i][j], mn + a[i - l + 1][i]);
            }
        }
    }

    ll ans = LLONG_MAX;
    for (int i = k; i <= n; i++) ans = min(ans, dp[n][i]);

    if (ans == LLONG_MAX) ans = -1;
    cout << ans << "\n";

    return 0;
}