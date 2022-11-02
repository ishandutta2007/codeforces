/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-21 07:53:11
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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e5 + 5;

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
}

int sz[MAXN],n,dep[MAXN],D;

inline void dfs(int v,int fa=0){
    sz[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dep[e[i].to] = dep[v] + 1;dfs(e[i].to,v);sz[v] += sz[e[i].to];
        D += 2ll*e[i].w*sz[e[i].to]*(n-sz[e[i].to]);
    }
}

struct Node{
    int u,v,w;
}a[MAXN];

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n-1){
        int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w);add(v,u,w);a[i] = (Node){u,v,w};
    }
    dfs(1);int q;scanf("%lld",&q);
//    DEBUG(D);
    while(q--){
        int id,w;scanf("%lld%lld",&id,&w);
        int u = a[id].u,v = a[id].v,ww = a[id].w;
        if(dep[u] > dep[v]) std::swap(u,v);
        D -= 2ll*sz[v]*(n-sz[v])*ww;
        a[id].w = w;
        D += 2ll*sz[v]*(n-sz[v])*w;
        printf("%.10f\n",3.0*D/n/(n-1));
    }
    return 0;
}