/*
 * Author: RainAir
 * Time: 2019-08-15 20:53:48
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
#define int LL
const int MAXN = 1e5+5;
const int MAXK = 500+5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],n,k,cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int sz[MAXN],f[MAXN][MAXK],ans;

inline void dfs(int v,int fa=0){
    sz[v] = 1;f[v][0] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs(e[i].to,v);
        FOR(x,0,k-1) ans += f[v][x]*f[e[i].to][k-x-1];
        FOR(x,1,k) f[v][x] += f[e[i].to][x-1];
        sz[v] += sz[e[i].to];
    }
}

signed  main(){
    scanf("%lld%lld",&n,&k);
    FOR(i,1,n-1){
        int u,v;scanf("%lld%lld",&u,&v);
        add(u,v);
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}