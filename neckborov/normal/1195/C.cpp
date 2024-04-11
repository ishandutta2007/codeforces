#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

using ll = long long;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        (a *= a) %= mod;
        p >>= 1;
    }
    return res;
}

const int N = 1e5 + 5;

ll dp[N][2], a[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i][1];
    }
    dp[1][0] = a[1][0];
    dp[1][1] = a[1][1];
    ll ans = max(a[1][0], a[1][1]);
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1] + a[i][0], max(dp[i - 2][0], dp[i - 2][1]) + a[i][0]);
        dp[i][1] = max(dp[i - 1][0] + a[i][1], max(dp[i - 2][0], dp[i - 2][1]) + a[i][1]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
    return 0;
}