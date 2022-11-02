#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 85, INF = 1e18;
int dp[N][N][N][2];
int cost[N][N];
vector<vector<pair<int,int>>> g(N);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    if (k == 1){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cost[i][j] = INF;
        }
    }
    vector<int> a;
    for (int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        a.pb(c);
        cost[u][v] = min(cost[u][v], c);
        g[u].pb({v, c});
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int q = 0; q < N; q++){
                dp[i][j][q][0] = dp[i][j][q][1] = INF;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (auto to : g[i]){
            if (to.first > i){
                dp[i][to.first][2][1] = min(dp[i][to.first][2][1], to.second);
                dp[to.first][n + 1][2][0] = min(dp[to.first][n + 1][2][0], to.second);
                dp[to.first][n][2][0] = min(dp[to.first][n][2][0], to.second);
            }
            else{
                dp[to.first][i][2][0] = min(dp[to.first][i][2][0], to.second);
                dp[0][to.first][2][1] = min(dp[0][to.first][2][1], to.second);
                dp[1][to.first][2][1] = min(dp[1][to.first][2][1], to.second);
            }
        }
    }
    for (int i = n + 1; i >= 1; i--){
        for (int l = 0; l + i <= n + 1; l++){
            int r = l + i;
            for (int f = 0; f < 2; f++){
                if (f == 0){
                    for (auto to : g[l]){
                        if (to.first >= l && to.first < r){
                            for (int j = 1; j < k; j++){
                                dp[to.first][r][j + 1][0] = min(dp[to.first][r][j + 1][0], dp[l][r][j][f] + to.second);
                                dp[l][to.first][j + 1][1] = min(dp[l][to.first][j + 1][1], dp[l][r][j][f] + to.second);
                            }
                        }
                    }
                }
                else{
                    for (auto to : g[r]){
                        if (to.first > l && to.first <= r){
                            for (int j = 1; j < k; j++){
                                dp[to.first][r][j + 1][0] = min(dp[to.first][r][j + 1][0], dp[l][r][j][f] + to.second);
                                dp[l][to.first][j + 1][1] = min(dp[l][to.first][j + 1][1], dp[l][r][j][f] + to.second);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int f = 0; f < 2; f++){
                ans = min(ans, dp[i][j][k][f]);
            }
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}