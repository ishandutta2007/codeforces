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
const llint N = 2e2 + 1, mod = 1e9 + 7;

vector < int > adj[N];
int n, m, ok[N], from[N], to[N], cs, level[N];
int delu, delv;

void dfs(int u){
    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(level[v] != 0) continue;
        if(v == delv) continue;
        level[v] = level[u] + 1;
        dfs(v);
    }
}

int get(int u){
    memset(level, 0, sizeof level);
    level[u] = 1;
    dfs(u);

    int node = 0;
    for(int i = 1; i <= n; ++i)
        if(level[i] > level[node])
            node = i;
    memset(level, 0, sizeof level);
    level[node] = 1; dfs(node);

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = max(ans, level[i]);
    return ans;
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int result = 0;
    for(int u = 1; u <= n; ++u){
        int sz = adj[u].size();
        for(int j = 0; j < sz; ++j){
             int v = adj[u][j];
             if(v < u) continue;
             delv = v;
             int ans = get(u) - 1;
             delv = u;
             ans *= get(v) - 1;
             result = max(result, ans);
        }
    }
    printf("%d", result);
}