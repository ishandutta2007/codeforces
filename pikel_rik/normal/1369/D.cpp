#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e6 + 5;

ll dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    dp[1] = dp[2] = 0;
    for (int i = 3; i < N; i++) {
        dp[i] = (2 * dp[i - 2] + dp[i - 1]) % mod;
        if (i % 3 == 0)
            dp[i] = (dp[i] + 1) % mod;
    }

    while (t--) {
        int n;
        cin >> n;

        cout << 4 * dp[n] % mod << "\n";
    }
    return 0;
}