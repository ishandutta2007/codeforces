#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define lc (x<<1)
#define se second
#define U unsigned
#define rc (x<<1|1)
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 500000+5;

struct Edge{
    int to,next;
}e[MAXN<<1];

int head[MAXN<<2],son[MAXN],size[MAXN],val[MAXN],dep[MAXN],fa[MAXN],a[MAXN],cnt,N;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
}

void dfs1(int v){
    size[v] = 1;if(v != 1) val[v] = val[fa[v]]^(1<<a[v]);
    for(int i = head[v];i;i = e[i].next){
        //if(e[i].to == fa[v]) continue;
        dep[e[i].to] = dep[v] + 1;fa[e[i].to] = v;
        dfs1(e[i].to);size[v] += size[e[i].to];
        son[v] = size[son[v]] < size[e[i].to] ? e[i].to : son[v];
    }
}

int maxv,f[MAXN<<5];

inline void calc(int v,int lca){
    int now = val[v];
    maxv = std::max(maxv,f[now]+dep[v]-2*dep[lca]);
    if(!(val[v]^val[lca])) maxv = std::max(maxv,dep[v]-dep[lca]);
    FOR(i,0,21){
        now = (1<<i)^val[v];
        maxv = std::max(maxv,f[now]+dep[v]-2*dep[lca]);
        if((val[v]^val[lca]) == (1<<i)) maxv = std::max(maxv,dep[v]-dep[lca]);
    }
    for(int i = head[v];i;i = e[i].next) calc(e[i].to,lca);
}

inline void change(int v,int k){
    if(k) f[val[v]] = std::max(f[val[v]],dep[v]);
    else f[val[v]] = INT_MIN;
    for(int i = head[v];i;i = e[i].next) change(e[i].to,k);
}
int ans[MAXN];
void dfs2(int v,int k){
    //DEBUG(v);
    for(int i = head[v];i;i = e[i].next){
        if(e[i].to == son[v]) continue;
        dfs2(e[i].to,0);
    }
    if(son[v]) dfs2(son[v],1);
    maxv = 0;int now = val[v];
    maxv = std::max(maxv,f[now]-dep[v]);
    FOR(i,0,21){
        now = (1<<i)^val[v];
        maxv = std::max(maxv,f[now]-dep[v]);
    }
    for(int i = head[v];i;i = e[i].next){
        if(e[i].to == son[v]) continue;
        calc(e[i].to,v);change(e[i].to,1);
    }
    ans[v] = maxv;
    if(!k){
        for(int i = head[v];i;i = e[i].next) change(e[i].to,0);
        f[val[v]] = INT_MIN;
    }else f[val[v]] = std::max(f[val[v]],dep[v]);
}

void erase(int v){
    for(int i = head[v];i;i = e[i].next){
        erase(e[i].to);
        ans[v] = std::max(ans[v],ans[e[i].to]);
    }
}

char str[20];

signed main(){
    scanf("%I64d",&N);
    FOR(i,2,N){
        int u;scanf("%I64d%s",&u,str+1);
        add(u,i);a[i] = str[1]-'a';
    }
    dep[1] = 1;dfs1(1);
    CLR(f,128);dfs2(1,0);
    erase(1);
    FOR(i,1,N) printf("%I64d ",ans[i]);puts("");
    return 0;
}