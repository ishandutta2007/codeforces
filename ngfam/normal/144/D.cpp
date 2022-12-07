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
const llint N = 1e5 + 1, mod = 1e9 + 7;
typedef pair<int,int> ii;

int dp[N], done[N], n, m, st, base;
priority_queue < ii, vector < ii >, greater < ii > > q;
vector < ii > adj[N];

void MAIN(){
    ///READ INPUT
    scanf("%d%d%d", &n, &m, &st);
    for(int i = 1; i <= m; ++i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }
    scanf("%d", &base);

    ///Dijkstra
    memset(dp, 63, sizeof dp);
    dp[st] = 0;

    q.push(ii(0, st));
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(done[u]) continue;
        done[u] = 1;

        int sz = adj[u].size();
        for(int i = 0; i < sz; ++i){
            int v = adj[u][i].first, w = adj[u][i].second;
            if(dp[v] > dp[u] + w){
                dp[v] = dp[u] + w;
                q.push(ii(dp[v], v));
            }
        }
    }
    ///Calculate

    int result = 0;
    for(int u = 1; u <= n; ++u){
        result += (dp[u] == base);
        int sz = adj[u].size();
        for(int i = 0; i < sz; ++i){
            int v = adj[u][i].first, w = adj[u][i].second;
            if(dp[u] < base && dp[u] + w > base){
                int len = w - (base - dp[u]);
                if(dp[v] + len < base){
                    continue;
                }
                if(dp[v] + len == base)
                    result -= (u < v);
                ++result;
            }
        }
    }
    printf("%d", result);
}