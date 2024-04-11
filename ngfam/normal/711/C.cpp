#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e2 + 1, mod = 1e9 + 7;

llint dp[N][N][N], n, m, k, c[N], p[N][N];

void MAIN(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) cin >> p[i][j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int h = 0; h <= k; ++h)
                dp[i][h][j] = mod * mod;
    if(c[1] == 0)
        for(int i = 1; i <= m; ++i) dp[1][1][i] = p[1][i];
    else dp[1][1][c[1]] = 0;

    for(int i = 2; i <= n; ++i)
        for(int f = 1; f <= k; ++f)
            for(int cl = 1; cl <= m; ++cl)
                if(c[i] == 0)
                    for(int cur = 1; cur <= m; ++cur){
                        if(cur == cl) dp[i][f][cur] = min(dp[i][f][cur], dp[i - 1][f][cl] + p[i][cur]);
                        else dp[i][f + 1][cur] = min(dp[i][f + 1][cur], dp[i - 1][f][cl] + p[i][cur]);
                    }
                else {
                    if(c[i] == cl) dp[i][f][c[i]] = min(dp[i][f][c[i]], dp[i - 1][f][cl]);
                    if(c[i] != cl) dp[i][f + 1][c[i]] = min(dp[i][f + 1][c[i]], dp[i - 1][f][cl]);
                }
    llint ans = mod * mod;
    for(int i = 1; i <= m; ++i) ans = min(ans, dp[n][k][i]);
    if(ans != mod * mod) cout << ans;
    else cout << -1;
}