#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 110, INF = 1e18;

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
        int n, ans = 0, sum = 0;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans += a[i] * a[i] * (n - 1);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            ans += b[i] * b[i] * (n - 1);
        }
        vector<int> dp(n * N, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            vector<int> dpp(n * N, INF);
            for (int j = 0; j < n * N; j++) {
                if (j + a[i] < n * N && j + b[i] < n * N) {
                    dpp[j + a[i]] = min(dpp[j + a[i]], dp[j] + 2 * a[i] * j + 2 * b[i] * (sum - j));
                    dpp[j + b[i]] = min(dpp[j + b[i]], dp[j] + 2 * b[i] * j + 2 * a[i] * (sum - j));
                }
            }
            dp = dpp;
            sum += a[i] + b[i];
        }
        int mn = INF;
        for (auto to : dp) mn = min(mn, to);
        cout << ans + mn << endl;
    }
    return 0;
}