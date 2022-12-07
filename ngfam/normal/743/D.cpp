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
const llint N = 3e5 + 1, mod = 1e9 + 7;

llint a[N], riki[N], ans = -mod * mod, super[N];
int n, par[N], ok, node = 0;
vector < int > adj[N];

void dfs(int u){
    riki[u] = a[u];
    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(v == par[u]) continue;
        par[v] = u; dfs(v);
        riki[u] += riki[v];
    }
}

void dfs2(int u){
    int sz = adj[u].size();
    super[u] = riki[u];
    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(v == par[u]) continue;
        dfs2(v);
        super[u] = max(super[u], super[v]);
    }
}


void dfs3(int u){
    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(v == par[u]) continue;
        if(node != 0){
            ok = true;
            ans = max(ans, super[v] + super[node]);
        }
        dfs3(v);
        if(super[v] > super[node] || node == 0) node = v;
    }
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", a + i);
    }
    for(int i = 1; i < n; ++i){
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1); dfs2(1); dfs3(1);
    if(!ok) puts("Impossible");
    else printf("%lld", ans);
}