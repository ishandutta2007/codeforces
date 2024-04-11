#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, k, dp[N][2], a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0, dummy; i < n; i++) cin >> dummy;

        sort(a, a + n);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(a, a + n, a[i] - k) - a;
            dp[i][0] = i - idx + 1;
            if (i > 0)
                dp[i][0] = max(dp[i][0], dp[i - 1][0]);
            if (idx > 0)
                dp[i][1] = i - idx + 1 + dp[idx - 1][0];
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        cout << ans << '\n';
    }
    return 0;
}