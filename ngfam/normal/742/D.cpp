/* Riven is not just my life :) */

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

int n, m, w, a[N], b[N], dp[N][N], ok[N][N], cur, done[N], best[N], shift[N];
int maxa[N], maxb[N];
vector < int > adj[N], tplt[N];

void dfs(int u){
    tplt[cur].push_back(u);
    shift[cur] += a[u];
    best[cur] += b[u];
    done[u] = 1;

    int sz = adj[u].size();

    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(!done[v]) dfs(v);
    }
}

typedef pair<int,int> ii;

ii ginz[N];

void MAIN(){
    scanf("%d%d%d", &n, &m, &w);

    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }

    for(int i = 1; i <= n; ++i){
        scanf("%d", b + i);
    }

    for(int i = 1; i <= m; ++i){
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i){
        if(!done[i]){
            ++cur;
            dfs(i);
        }
    }

    for(int i = 1; i <= cur; ++i){
        if(shift[i] <= w){
            ginz[i] = ii(shift[i], best[i]);
        }
        else{
            ginz[i] = ii(mod, -mod);
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= w; ++j){
            dp[i][j] = -mod;
        }
    }

    int ans = 0;

    for(int i = 1; i <= cur; ++i){


        for(int wei = w; wei >= 0; --wei){
            dp[i][wei] = dp[i - 1][wei];
            if(ginz[i].first <= wei){
                dp[i][wei] = max(dp[i][wei], dp[i - 1][wei - ginz[i].first] + ginz[i].second);
            }
            int sz = tplt[i].size();
            for(int j = 0; j < sz; ++j){
                int u = tplt[i][j];
                if(a[u] <= wei){
                    dp[i][wei] = max(dp[i][wei], dp[i - 1][wei - a[u]] + b[u]);
                }
            }
            ans = max(ans, dp[i][wei]);
        }
    }
    printf("%d", ans);
}