#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int INF = 1e18;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = min(a[i], n + 1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> dp(n + 1, -INF);
            dp[i] = 0;
            for (int j = i; j < n; j++) {
                int now = 0;
                vector<bool> used(n + 2);
                for (int k = j; k < n; k++) {
                    used[a[k]] = 1;
                    while (used[now]) now++;
                    dp[k + 1] = max(dp[k + 1], dp[j] + now + 1);
                }
            }
            for (int j = i; j <= n; j++) {
                ans += dp[j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}