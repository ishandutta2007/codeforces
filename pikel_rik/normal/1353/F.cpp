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
const int N = 1e2 + 5;

int n, m;
ll a[N][N], dp[N][N];

ll f(ll x) {
    dp[1][1] = a[1][1] - x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 and j == 1) continue;
            dp[i][j] = LLONG_MAX;
            if ((i == 1 ? LLONG_MAX : dp[i - 1][j]) == LLONG_MAX and (j == 1 ? LLONG_MAX : dp[i][j - 1]) == LLONG_MAX)
                continue;
            if (a[i][j] >= x + i - 1 + j - 1)
                dp[i][j] = a[i][j] - (x + i - 1 + j - 1) + min((i == 1 ? LLONG_MAX : dp[i - 1][j]), (j == 1 ? LLONG_MAX : dp[i][j - 1]));
        }
    }
    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];

        ll best = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] - (i - 1 + j - 1) <= a[1][1])
                best = min(best, f(a[i][j] - (i - 1 + j - 1)));
            }
        }

        cout << best << "\n";
    }
    return 0;
}