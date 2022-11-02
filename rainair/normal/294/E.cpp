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
#define P std::pair<LL,LL>
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
const int MAXN = 1e5 + 5;

struct Edge{
    int u,v,w;
}e[MAXN];
int n;
bool vis[MAXN];
int col[MAXN],max[MAXN];
std::vector<P> G[MAXN];
LL ans = 0;int sz[MAXN];
int sz1,sz2,rt1,rt2;
int f[MAXN];LL sum;

inline void dfs1(int v,int c,int fa=0){
    col[v] = c;
    for(auto x:G[v]){
        if(x.fi == fa) continue;
        dfs1(x.fi,c,v);
    }
}

inline void dfs2(int v,int tp,int fa=0){
    sz[v] = 1;max[v] = 0;
    for(auto x:G[v]){
        if(x.fi == fa) continue;
        dfs2(x.fi,tp,v);sz[v] += sz[x.fi];
        max[v] = std::max(max[v],sz[x.fi]);
        //DEBUG(max[v]);DEBUG(sz[x.fi]);DEBUG(v);
    }
    int t = tp == 1 ? sz1 : sz2;
    max[v] = std::max(max[v],t-sz[v]);
    if(tp == 1) rt1 = max[rt1] > max[v] ? v : rt1;
    else rt2 = max[rt2] > max[v] ? v : rt2;
}

inline void dfs3(int v,int fa=0){
    sz[v] = 1;
    for(auto x:G[v]){
        if(x.fi == fa) continue;
        dfs3(x.fi,v);sz[v] += sz[x.fi];
    }
    for(auto x:G[v]){
        if(x.fi == fa) continue;
        sum += sz[x.fi]*(n-sz[x.fi])*x.se;
    }
}

inline void init(){
    sz1 = sz2 = rt1 = rt2 = 0;
    FOR(i,1,n) G[i].clear();
    FOR(i,1,n) vis[i] = sz[i] = col[i] = max[i] = 0;sum = 0;
}

signed main(){
    scanf("%lld",&n);ans = LLONG_MAX;
    FOR(i,1,n-1) scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    FOR(k,1,n-1){
      //  DEBUG(k);
        init();
        FOR(i,1,n-1) if(i != k) G[e[i].u].pb(MP(e[i].v,e[i].w)),G[e[i].v].pb(MP(e[i].u,e[i].w));
        rt1 = 1;dfs1(rt1,1);sz[0] = n;max[0] = n;
        rt2 = 1;while(col[rt2]) rt2++;dfs1(rt2,2);
        FOR(i,1,n) if(col[i] == 1) sz1++;else sz2++;
        int t = rt1;rt1 = 0;dfs2(t,1);t = rt2;rt2 = 0;dfs2(t,2);
        G[rt1].pb(MP(rt2,e[k].w));G[rt2].pb(MP(rt1,e[k].w));
        FOR(i,1,n) sz[i] = 0;sum = 0;
        dfs3(1);
        ans = std::min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}