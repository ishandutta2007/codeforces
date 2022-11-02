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
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        reverse(a.begin(), a.end());
        int m = 2;
        while(m * (m + 1) / 2 <= n) m++;
        vector<vector<int>> dp(n + 1, vector<int>(m, -INF));
        dp[0][0] = INF;
        for (int i = 1; i <= n; i++){
            int sum = 0;
            for (int j = 0; j < m; j++) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            for (int j = i; j <= n; j++){
                if (j - i + 1 >= m) break;
                sum += a[j - 1];
                if (dp[i - 1][j - i] > sum){
                    dp[j][j - i + 1] = max(dp[j][j - i + 1], sum);
                }
            }
        }
        for (int i = m - 1; i >= 1; i--){
            if (dp[n][i] != -INF){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}