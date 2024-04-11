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
const llint N = 3e2 + 1, mod = 1e9 + 7;

int  n, m, k;
llint dp[N][N];

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            scanf("%lld", &dp[i][j]);
        }

    scanf("%d", &k);
    for(int i = 1; i <= k; ++i){
        int u, v; llint w;
        scanf("%d%d%lld", &u, &v, &w);
        if(u > v) swap(u, v);
        dp[u][v]  = dp[v][u] = min(dp[u][v], w);

        for(int v1 = 1; v1 <= n; ++v1)
            for(int v2 = 1; v2 <= n; ++v2)
                 if(v1 != v2){
                      dp[v1][v2] = min(dp[v1][v2], dp[v1][u] + dp[u][v] + dp[v][v2]);
                      dp[v1][v2] = min(dp[v1][v2], dp[v1][v] + dp[v][u] + dp[u][v2]);
                 }

        llint ans = 0;
        for(int v1 = 1; v1 <= n; ++v1)
            for(int v2 = v1 + 1; v2 <= n; ++v2)
                ans += dp[v1][v2];
        printf("%lld ", ans);
    }
}