//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int N = 3e5 + 5;
const int K = 5;

ll dp[N][K];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        for (int i = 0; i < K; i++) {
            dp[0][i] = a[0].second * i;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < K; j++) {
                dp[i][j] = LLONG_MAX;
                for (int k = 0; k < K; k++) {
                    if (a[i].first + j != a[i - 1].first + k) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + a[i].second * j);
                    }
                }
            }
        }
        ll ans = LLONG_MAX;
        for (int k = 0; k < K; k++) {
            ans = min(ans, dp[n - 1][k]);
        }
        cout << ans << '\n';
    }
}