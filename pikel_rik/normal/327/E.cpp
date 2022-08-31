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
const int N = 24;

int n, a[N], k, b[2];
ll dp[(1 << N)];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> k;
    for (int i = 0; i < k; i++) cin >> b[i];

    for (int i = 1; i < (1 << n); i++) {
        int j = __builtin_ctz(i);
        dp[i] = dp[i ^ (1 << j)] + a[j];
    }

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < k; j++) {
            if (dp[i] == b[j])
                dp[i] = -1;
        }
    }

    dp[0] = 1;
    for (int i = 1; i < (1 << n); i++) {
        if (dp[i] < 0) {
            dp[i] = 0;
            continue;
        }
        dp[i] = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                dp[i] += dp[i ^ (1 << j)];
            }
        }
        dp[i] %= mod;
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}