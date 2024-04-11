#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int INF = 1e9;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int mn = m;
        vector<int> dp(m + 1, -INF), a(n), cnt(m + 1), total(m + 1);
        cnt[0] = INF;
        for (int i = 0; i <= m; i++) {
            dp[i] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
            cnt[a[i]]++;
            total[a[i]]++;
        }
        int ans = m, mx = m;
        for (int i = m; i >= 1; i--) {
            if ((ll)i * i <= m) {
                for (int j = i * i; j <= m; j += i) {
                    cnt[dp[j]] -= total[j];
                    dp[j] = min(dp[j], dp[j / i]);
                    cnt[dp[j]] += total[j];
                }
            }
            while (cnt[mx] == 0) {
                mx--;
            }
            if (i <= mn) {
                ans = min(ans, mx - i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}