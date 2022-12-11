#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 50;
int temp[maxn], *f[maxn], *id = temp;
int len[maxn], son[maxn], ans[maxn];
vector<int> g[maxn];
int n;
void dfs(int u, int fa){// && 
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v, u); if(len[v] > len[son[u]]) son[u] = v;
    } len[u] = len[son[u]]+1; return;
}
void dp(int u, int fa){
    ans[u] = 0;
    f[u][0] = 1;
    if(son[u]){
        f[son[u]] = f[u] + 1; dp(son[u], u); ans[u] = ans[son[u]] + 1;
    }
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(v==fa || v==son[u]) continue;
        f[v] = id; id += len[v];
        dp(v, u);
        for(int j = 0; j < len[v]; ++j) {
            f[u][j+1] += f[v][j];
            if(f[u][ans[u]] < f[u][j+1]) ans[u] = j+1;
            else if(f[u][ans[u]] == f[u][j+1]) ans[u] = min(ans[u], j+1);
        }
    }
    if(f[u][ans[u]] == 1) ans[u] = 0;
    //cout<<"u:"<<u<<endl;for(int i = 0; i < len[u]; ++i) cout<<f[u][i]<<" "; cout<<endl<<endl;
}
int main(){
    cin>>n;
    for(int i = 1; i < n; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    f[1] = id; id += len[1];
    dp(1, 1);
    for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
}