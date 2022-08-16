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

int n, l, k, a[N];
double p[N], dp[N][N];

double mp[N][N][2*N + 1];

double recurse(int i, int j, int cap) {
    if (j == 0)
        return (cap >= 0) * dp[i][0];
    if (cap >= j)
        return dp[i][j];
    if (mp[i][j][N + cap] != -1)
        return mp[i][j][N + cap];
    return mp[i][j][N + cap] = p[i] * recurse(i - 1, j - 1, cap + a[i]) + (i > j ? (1 - p[i]) * recurse(i - 1, j, cap) : 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> k;
    for (int i = 1; i <= n; i++) cin >> p[i], p[i] /= 100;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = -n; k <= n; k++) {
                mp[i][j][N + k] = -1;
            }
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = (1 - p[i]) * dp[i - 1][0];
        for (int j = 1; j <= i; j++) {
            dp[i][j] = p[i] * dp[i - 1][j - 1] + (1 - p[i]) * dp[i - 1][j];
        }
    }

    double ans = 0;
    for (int i = l; i <= n; i++)
        ans += recurse(n, i, k);

    cout << fixed << setprecision(12);
    cout << ans << "\n";
    return 0;
}