#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, m, k;

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<vector<int>> right(n, vector<int>(m)), down(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m - 1; j++){
            cin >> right[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m; j++){
            cin >> down[i][j];
        }
    }
    if (k % 2 == 1){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << -1 << " ";
            }
            cout << endl;
        }
        return 0;
    }
    k /= 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, 1e18)));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            dp[i][j][0] = 0;
        }
    }
    for (int f = 0; f < k; f++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (j + 1 < m){
                    dp[i][j + 1][f + 1] = min(dp[i][j + 1][f + 1], dp[i][j][f] + right[i][j] * 2);
                }
                if (j - 1 >= 0){
                    dp[i][j - 1][f + 1] = min(dp[i][j - 1][f + 1], dp[i][j][f] + right[i][j - 1] * 2);
                }
                if (i + 1 < n){
                    dp[i + 1][j][f + 1] = min(dp[i + 1][j][f + 1], dp[i][j][f] + down[i][j] * 2);
                }
                if (i - 1 >= 0){
                    dp[i - 1][j][f + 1] = min(dp[i - 1][j][f + 1], dp[i][j][f] + down[i - 1][j] * 2);
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << dp[i][j][k] << " ";
        }
        cout << endl;
    }
    return 0;
}