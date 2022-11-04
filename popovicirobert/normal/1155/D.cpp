#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 1e18;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;

    vector <int> arr(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector < vector <ll> > dp(n + 1, vector <ll>(3, -INF));

    ll ans = 0;
    dp[0][0] = 0;

    for(i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + arr[i];
        dp[i][1] = max(dp[i - 1][1] + 1LL * arr[i] * x, dp[i - 1][0] + 1LL * x * arr[i]);
        dp[i][2] = max(dp[i - 1][2] + arr[i], dp[i - 1][1] + arr[i]);

        for(int j = 0; j < 3; j++) {
            dp[i][j] = max(dp[i][j], 0LL);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}