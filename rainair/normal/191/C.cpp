/*
 * Author: RainAir
 * Time: 2019-08-07 21:48:17
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
std::vector<int> G[MAXN];
int n;int dep[MAXN],f[21][MAXN];
int ans[MAXN];

inline void dfs(int v,int fa=0){
    FOR(i,1,20) f[i][v] = f[i-1][f[i-1][v]];
    for(auto x:G[v]){
        if(x == fa) continue;
        f[0][x] = v;dep[x] = dep[v] + 1;dfs(x,v);
    }
}

inline int lca(int x,int y){
    if(dep[x] != dep[y]){
        if(dep[x] < dep[y]) std::swap(x,y);
        int d = dep[x]-dep[y];
        FOR(i,0,20){
            if((1<<i)&d) x = f[i][x];
        }
    }
    if(x == y) return x;
    ROF(i,20,0){
        if(f[i][x] == f[i][y]) continue;
        x = f[i][x],y = f[i][y];
    }
    return f[0][x];
}

inline void dfss(int v,int fa=0){
    for(auto x:G[v]){
        if(x == fa) continue;
        dfss(x,v);ans[v] += ans[x];
    }
}

std::pair<int,int> edge[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);edge[i] = MP(u,v);
    }
    dfs(1);int m;scanf("%d",&m);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        int l = lca(u,v);
        ans[u]++;ans[v]++;ans[l]-=2;
    }
    dfss(1);
    FOR(i,2,n){
        int u = edge[i].fi,v = edge[i].se;
        if(dep[u] < dep[v]) std::swap(u,v);
        printf("%d ",ans[u]);
    }
    return 0;
}