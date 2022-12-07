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

int n, m, k, level[N], par[N];
vector < int > adj[N];

void write(int u, int v){
    if(u != v) write(par[u], v);
    printf("%d ", u);
}

void dfs(int u){
    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(level[v] == 0){
            par[v] = u;
            level[v] = level[u] + 1;
            dfs(v);
        }
        else{
            if(level[u] - level[v] > k - 1){
                printf("%d\n", level[u] - level[v] + 1);
                write(u, v);
                exit(0);
            }
        }
    }
}

void MAIN(){
    ///READ INPUT
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; ++i){
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ///SOLVE
    level[1] = 1; dfs(1);
}