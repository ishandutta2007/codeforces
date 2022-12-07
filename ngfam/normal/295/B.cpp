/*** Riven is not just my life :) ***/

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
const llint N = 1e3 + 1, mod = 1e9 + 7;

int x[N], n;
llint dp[N][N], result[N], a[N][N], old[N][N], ans;

void MAIN(){
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            scanf("%lld", &a[i][j]);
        }
    }

    for(int i = 1; i <= n; ++i){
        scanf("%d", x + i);
    }

    memset(dp, 60, sizeof dp);
    vector < int > vertice;
    for(int t = n; t >= 1; --t){
        int u = x[t], sz = vertice.size();
        dp[u][u] = old[u][u] = 0;
        for(int i = 0; i < sz; ++i){
            int v = vertice[i];
            for(int j = 0; j < sz; ++j){
                int k = vertice[j];
                dp[v][u] = min(dp[v][u], dp[v][k] + a[k][u]);
            }
            ans += dp[v][u];
            old[v][u] = dp[v][u];
        }

        for(int i = 0; i < sz; ++i){
            int v = vertice[i];
            for(int j = 0; j < sz; ++j){
                int k = vertice[j];
                dp[u][v] = min(dp[u][v], a[u][k] + dp[k][v]);
            }
            ans += dp[u][v];
            old[u][v] = dp[u][v];
        }
        for(int i = 0; i < sz; ++i){
            for(int j = 0; j < sz; ++j){
                int v = vertice[i], k = vertice[j];
                dp[v][k] = min(dp[v][k], dp[v][u] + dp[u][k]);
            }
        }

        for(int i = 0; i < sz; ++i){
            for(int j = 0; j < sz; ++j){
                int v = vertice[i], k = vertice[j];
                if(v == u || k == u) continue;
                ans -= old[v][k] - dp[v][k];
                old[v][k] = dp[v][k];
            }
        }
        vertice.push_back(u);
        result[t] = ans;
    }

    for(int i = 1; i <= n; ++i){
        printf("%lld ", result[i]);
    }
}