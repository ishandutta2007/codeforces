#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

ll dp[100001][101];

ll choose(int n, int k) {
    if (k == 0 or k == n)
        return 1;

    if (dp[n][k] != -1)
        return dp[n][k];

    return dp[n][k] = choose(n - 1, k) + choose(n - 1, k - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i <= 100000; i++) for (int j = 1; j <= 100; j++) dp[i][j] = -1;

    int n, m, h;
    cin >> n >> m >> h;

    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];

    a[h] -= 1;
    ll total = accumulate(all(a), 0), ans = 0;

    if (total + 1 < n) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= a[h]; i++) {
        if (total - a[h] >= n - i - 1 and n - i - 1 >= 0)
            ans += choose(a[h], i) * choose(total - a[h], n - i - 1);
    }

    cout << fixed << setprecision(10);
    cout << ans / choose(total, n - 1);
    return 0;
}