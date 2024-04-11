#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        if (n > m) swap(n, m);
        int mn = (n - 1) + n * (m - 1);
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (i > 0){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + j + 1);
                }
                if (j > 0){
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + i + 1);
                }
            }
        }
        if (mn <= k && k <= dp[n - 1][m - 1]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}