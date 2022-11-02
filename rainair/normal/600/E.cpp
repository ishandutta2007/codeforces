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

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 100000+5;

int head[MAXN],cnt,size[MAXN],son[MAXN],dep[MAXN],fa[MAXN];
int ans[MAXN],val[MAXN],c[MAXN],maxv,sum;
int N;

struct Edge{
    int to,next;
}e[MAXN<<1];

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
}

void dfs1(int v){
    size[v] = 1;
    for(int i = head[v];i;i = e[i].next){
        if(e[i].to == fa[v]) continue;
        dep[e[i].to] = dep[v]+1;fa[e[i].to] = v;
        dfs1(e[i].to);size[v] += size[e[i].to];
        son[v] = (size[son[v]] < size[e[i].to]) ? e[i].to : son[v];
    }
}

bool vis[MAXN];

void change(int v,int fa,int k){
    c[val[v]] += k;
    if(k > 0 && c[val[v]] >= maxv){
        if(c[val[v]] > maxv) sum = 0,maxv = c[val[v]];
        sum += val[v];
    }
    for(int i = head[v];i;i = e[i].next){
        if(vis[e[i].to] || e[i].to == fa) continue;
        change(e[i].to,v,k);
    }
}

void dfs2(int v,int fa=0,bool used=false){
    for(int i = head[v];i;i = e[i].next){
        if(e[i].to == fa || e[i].to == son[v]) continue;
        dfs2(e[i].to,v);
    }
    if(son[v]) dfs2(son[v],v,1),vis[son[v]] = true;
    change(v,fa,1);ans[v] = sum;
    if(son[v]) vis[son[v]] = false;
    if(!used) change(v,fa,-1),maxv = sum = 0;
}

signed main(){
    scanf("%I64d",&N);
    FOR(i,1,N) scanf("%I64d",val+i);
    FOR(i,1,N-1){
        int u,v;scanf("%I64d%I64d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs1(1);dfs2(1);
    FOR(i,1,N) printf("%I64d ",ans[i]);puts("");
    return 0;
}