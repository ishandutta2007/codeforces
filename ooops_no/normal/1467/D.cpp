#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long
#define ld long double

mt19937 rnd(51);

const int MOD = 1e9 + 7;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q, ans = 0;
    cin >> n >> k >> q;
    vector<int> a(n);
    vector<int> sum(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int j = 0; j < k; j++){
        for (int i = 0; i < n; i++){
            if (i - 1 >= 0) {
                dp[i - 1][j + 1] += dp[i][j];
                if (dp[i - 1][j + 1] > MOD) dp[i - 1][j + 1] -= MOD;
            }
            if (i + 1 < n){
                dp[i + 1][j + 1] += dp[i][j];
                if (dp[i + 1][j + 1] > MOD) dp[i + 1][j + 1] -= MOD;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= k; j++){
            sum[i] = (sum[i] + dp[i][j] * dp[i][(k - j)]) % MOD;
        }
        ans += a[i] * sum[i];
        ans %= MOD;
    }
    while(q--){
        int i, x;
        cin >> i >> x;
        i--;
        ans -= a[i] * sum[i];
        a[i] = x;
        ans += a[i] * sum[i];
        ans = (ans % MOD + MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}