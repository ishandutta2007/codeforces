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
        int n;
        cin >> n;
        vector<int> a(n), dp(n, -INF);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> cnt(n);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && mx <= i / 2) {
                dp[i] = 1;
            }
            cnt[a[i]]++;
            mx = max(mx, cnt[a[i]]);
        }
        for (int i = 0; i < n; i++) {
            fill(cnt.begin(), cnt.end(), 0);
            mx = 0;
            for (int j = i + 1; j < n; j++) {
                cnt[a[j]]++;
                mx = max(mx, cnt[a[j]]);
                if ((j - i) % 2 == 0 && a[j + 1] == a[i]) {
                    if (mx <= (j - i) / 2) {
                        dp[j + 1] = max(dp[j + 1], dp[i] + 1);
                    }
                }
            }
            if (i + 1 < n && a[i] == a[i + 1]) {
                dp[i + 1] = max(dp[i + 1], dp[i] + 1);
            }
        }
        fill(cnt.begin(), cnt.end(), 0);
        mx = 0;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ((n - i) % 2 == 1) {
                if (mx <= (n - i) / 2) {
                    ans = max(ans, dp[i]);
                }
            }
            cnt[a[i]]++;
            mx = max(mx, cnt[a[i]]);
        }
        cout << ans << endl;
    }
    return 0;
}