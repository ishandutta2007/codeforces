#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn = 1e5 + 50;
vector<int> g[maxn];
int son[maxn], sz[maxn], a[maxn], ha[maxn], vis[maxn], fa[maxn];
ll ans[maxn];
ll mx, sum;
int n;
void dfs(int u, int f){
    sz[u] = 1;son[u] = 0;fa[u] = f;
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(v == f) continue;
        dfs(v, u); sz[u] += sz[v]; if(sz[v] > sz[son[u]]) son[u] = v;
    }
}
void init(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i < n; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
}
void cal(int u, int x){
    ha[a[u]] += x;
    if(ha[a[u]] == mx && x > 0) sum += a[u];
    else if(ha[a[u]] > mx && x > 0) mx = ha[a[u]], sum = a[u];
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(vis[v] || v == fa[u]) continue;
        cal(v, x);
    }
}
void sol(int u, int del)
{
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(v == son[u] || v == fa[u]) continue;
        sol(v, 1);
    }
    if(son[u]) sol(son[u], 0), vis[son[u]] = 1;
    cal(u, 1);
    ans[u] = sum;
    if(son[u]) vis[son[u]] = 0;
    if(del) cal(u, -1), mx = sum = 0;
    return;
}
void sol()
{
    sol(1, 0);
    for(int i = 1; i <= n; ++i){
        if(i > 1) printf(" ");
        printf("%I64d", ans[i]);
    }printf("\n");
}
int main()
{
    init();sol();
}