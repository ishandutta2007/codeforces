// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 5005;
const int mod = 998244353;

ll dp[N][N], pref[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][1] = 1;
        pref[i][1] = i + 1;
    }

    sort(a.begin(), a.end());
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cnt[i] = upper_bound(a.begin(), a.end(), a[i] / 2) - a.begin();
    }

    for (int j = 2; j <= n; j++) {
        for (int i = 0; i < n; i++) {
            if (cnt[i] >= j - 1) {
                (dp[i][j] += dp[i][j - 1] * (cnt[i] - j + 2)) %= mod;
            }
            if (cnt[i]) {
                (dp[i][j] += pref[cnt[i] - 1][j - 1]) %= mod;
            }
        }
        for (int i = 0; i < n; i++) {
            pref[i][j] += (i ? pref[i - 1][j] : 0) + dp[i][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        (ans += dp[i][n]) %= mod;
    }
    cout << ans << endl;
    return 0;
}