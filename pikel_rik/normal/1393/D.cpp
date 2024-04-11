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
const int N = 2e3 + 5;

int n, m, dp[N][N];
string a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 1 and j > 0 and j + 1 < m and a[i][j] == a[i - 1][j - 1] and a[i][j] == a[i - 1][j + 1] and a[i][j] == a[i - 2][j] and a[i][j] == a[i - 1][j])
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j + 1], dp[i - 2][j]});
            else dp[i][j] = 1;
            ans += dp[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}