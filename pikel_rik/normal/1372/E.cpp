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
const int N = 100 + 5;

int n, m, a[N][N], b[N][N], dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int l, r;
            cin >> l >> r;
            for (int j = l; j <= r; j++) {
                a[i][j] = l;
                b[i][j] = r;
            }
        }
    }

    for (int l = m; l >= 1; l--) {
        for (int r = l; r <= m; r++) {
            for (int j = l; j <= r; j++) {
                int amt = 0;
                for (int i = 1; i <= n; i++) {
                    if (a[i][j] >= l and b[i][j] <= r) {
                        amt++;
                    }
                }
                dp[l][r] = max(dp[l][r], dp[l][j - 1] + amt * amt + dp[j + 1][r]);
            }
        }
    }

    cout << dp[1][m] << "\n";
    return 0;
}