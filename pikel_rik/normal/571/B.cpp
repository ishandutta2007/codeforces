#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 3e5 + 5;
const int K = 5000 + 5;

int n, k, a[N];
ll dp[K][K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    dp[0][0] = 0;
    for (int c1 = 0; c1 <= k - n % k; c1++) {
        for (int c2 = 0; c2 <= n % k; c2++) {
            if (c1 == 0 and c2 == 0) continue;

            dp[c1][c2] = INT_MAX;
            int i = c1 * (n / k) + c2 * (n / k + 1);
            if (c1 > 0)
                dp[c1][c2] = min(dp[c1][c2], a[i] - a[i - n / k + 1] + dp[c1 - 1][c2]);
            if (c2 > 0)
                dp[c1][c2] = min(dp[c1][c2], a[i] - a[i - n / k] + dp[c1][c2 - 1]);
        }
    }

    cout << dp[k - n % k][n % k] << "\n";
    return 0;
}