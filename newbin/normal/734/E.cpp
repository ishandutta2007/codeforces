#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn= 2e5 + 50;
int to[maxn];
vector<int> g[maxn], G[maxn];
int c[maxn];
int n;
void dfs(int u, int tot){
    to[u] = tot;
    for(int v: g[u]) if(c[v] == c[u] && !to[v]) dfs(v, tot);
}
int ans;
int dep[maxn];
void DFS(int u, int fa){
    dep[u] = 1;
    for(int v: G[u]){
        if(v == fa) continue;
        DFS(v, u);
        ans = max(ans, dep[u]+dep[v]);
        dep[u] = max(dep[u], dep[v]+1);
    }
}
int main()
{
    scanf("%d", &n); for(int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    for(int i = 1; i < n; ++i){
        int u, v; scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }
    int tot = 0;
    for(int i = 1; i <= n; ++i) if(!to[i]) dfs(i, ++tot);
    for(int i = 1; i <= n; ++i){
        for(int v: g[i]) if(to[v] != to[i]) G[to[i]].pb(to[v]);
    }
    ans = 1;
    DFS(1, 1);
    cout<<ans/2<<endl;
}