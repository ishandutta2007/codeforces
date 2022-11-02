/*
 * Author: RainAir
 * Time: 2019-07-13 09:55:29
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
std::vector<int> G[MAXN],red;
int n,m,B;
int dep[MAXN],f[21][MAXN];

inline void dfs(int v,int fa=0){
    f[0][v] = fa;
    FOR(i,1,20) f[i][v] = f[i-1][f[i-1][v]];
    for(auto x:G[v]){
        if(x == fa) continue;
        dep[x] = dep[v] + 1;
        dfs(x,v);
    }
}

inline int lca(int x,int y){
    if(dep[x] != dep[y]){
        if(dep[x] < dep[y]) std::swap(x,y);
        int d = dep[x] - dep[y];
        ROF(i,20,0) if(d&(1<<i)) x = f[i][x];
    }
    if(x == y) return x;
    ROF(i,20,0){
        if(f[i][x] == f[i][y]) continue;
        x = f[i][x],y = f[i][y];
    }
    return f[0][x];
}

inline int calc(int x,int y){
    int l = lca(x,y);
    return dep[x]+dep[y]-2*dep[l];
}

int dis[MAXN],inq[MAXN];

inline void spfa(){
    std::queue<int> q;
    FOR(i,1,n) dis[i] = 1e9,inq[i] = false;
    for(auto x:red) dis[x] = 0,inq[x] = true,q.push(x);
    while(!q.empty()){
        int v = q.front();q.pop();inq[v] = false;
        for(auto x:G[v]){
            if(dis[x] > dis[v] + 1){
                dis[x] = dis[v] + 1;
                if(!inq[x]) q.push(x),inq[x] = true;
            }
        }
    }
}
std::vector<int> now;
inline void Solve(int len){
    spfa();now.clear();
    FOR(i,1,len){
        int opt,x;scanf("%d%d",&opt,&x);
        if(opt == 1){
            now.pb(x);red.pb(x);
        }
        else{
            int ans = dis[x];
            for(auto j:now) ans = std::min(ans,calc(j,x));//,DEBUG(calc(j,x));
            printf("%d\n",ans);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);B = std::sqrt(1.0*m);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    dfs(1);red.pb(1);
    FOR(i,1,B){
        Solve(B);
    }
    if(m-B*B > 0) Solve(m-B*B);
    return 0;
}