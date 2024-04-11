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

int n, m, k, nodes[N], tplt[N], cur, done[N], ok[N][N], ginz[N];
vector < int > adj[N], inside[N];

void dfs(int u){
    if(nodes[u]) ginz[cur] = 1;
    done[u] = 1;
    ++tplt[cur];
    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(done[v]) continue;
        dfs(v);
    }
}

void MAIN(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= k; ++i){
        int u; scanf("%d", &u);
        nodes[u] = true;
    }

    for(int i = 1; i <= m; ++i){
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        ok[u][v] = ok[v][u] = 1;
    }

    int maxnodes = 0, total = 0;

    int ans = 0;

    for(int i = 1; i <= n; ++i){
        if(!done[i]){
            ++cur;
            dfs(i);
            if(ginz[cur]){
                maxnodes = max(maxnodes, tplt[cur]);
            }
            else{
                total += tplt[cur];
                ans -= (tplt[cur] * (tplt[cur] - 1)) / 2;
            }
        }
    }
    ans += (total * (total - 1)) / 2 + maxnodes * total;

    for(int i = 1; i <= cur; ++i){
        ans += (tplt[i] * (tplt[i] - 1)) / 2;
    }
    ans -= m;

    printf("%d", ans);
}