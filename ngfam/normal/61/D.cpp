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
const llint N = 1e5 + 1, mod = 1e9 + 7;

typedef pair<int,int> ii;

int n, par[N];
llint path[N], ans, maxpath;

vector < ii > adj[N];

void dfs(int u){
    int sz = adj[u].size();

    maxpath = max(maxpath, path[u]);

    for(int i = 0; i < sz; ++i){
        int v = adj[u][i].first, w = adj[u][i].second;
        if(v == par[u]) continue;

        par[v] = u;
        path[v] = path[u] + w;
        dfs(v);
    }
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));

        ans += 2 * w;
    }

    dfs(1);
    ans -= maxpath;
    cout << ans;
}