#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 500 + 5;

int n, m, b, a[N], dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> b >> mod;
    for (int i = 0; i < n; i++) cin >> a[i];

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= b; k++) {
                if (dp[j][k] and k + a[i] <= b) {
                    dp[j + 1][k + a[i]] = (dp[j + 1][k + a[i]] + dp[j][k]) % mod;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= b; i++) {
        ans = (ans + dp[m][i]) % mod;
    }
    cout << ans << '\n';
    return 0;
}