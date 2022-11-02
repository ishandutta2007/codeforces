// ss
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

const int MAXN = 1000000+5;

struct Edge{
    int to,next;
}e[MAXN<<1];
int head[MAXN],len[MAXN],son[MAXN],fa[MAXN],cnt,t[MAXN<<2];
int *f[MAXN],*id = t,ans[MAXN],N;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
}

inline void dfs(int v){
    for(int i = head[v];i;i = e[i].next){
        if(e[i].to != fa[v]){
            fa[e[i].to] = v;
            dfs(e[i].to);
            son[v] = len[e[i].to] > len[son[v]] ? e[i].to : son[v];
        }
    }
    len[v] = len[son[v]]+1;
}

void dp(int v){
    // DEBUG(v);
    f[v][0] = 1;
    if(son[v]){
        f[son[v]] = f[v] + 1;
        dp(son[v]);ans[v] = ans[son[v]] + 1;
    }
    for(int i = head[v];i;i = e[i].next){
        if(e[i].to == fa[v] || e[i].to == son[v]) continue;
        f[e[i].to] = id;id += len[e[i].to];dp(e[i].to);
        FOR(j,1,len[e[i].to]){
            f[v][j] += f[e[i].to][j-1];
            if((j < ans[v] && f[v][j] >= f[v][ans[v]]) || (j > ans[v] && f[v][j] > f[v][ans[v]]))
                ans[v] = j;
        }
    }
    if(f[v][ans[v]] == 1) ans[v] = 0;
}

int main(){
    scanf("%d",&N);
    FOR(i,1,N-1){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1);f[1] = id;id += len[1];
    dp(1);
    FOR(i,1,N) printf("%d\n",ans[i]);
    return 0;
}