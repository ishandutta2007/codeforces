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
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int n,a,b;

int F[MAXN],G[MAXN],fa[MAXN],dep[MAXN];
// F:  G: 

inline void up(int v,int fa=0){
    F[v] = 0;::fa[v] = fa;dep[v] = dep[fa]+1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        up(e[i].to,v);
        F[v] = std::max(F[v],F[e[i].to]+1);
    }
}

int pre[MAXN],suf[MAXN];
inline void down(int v,int fa=0){
    std::vector<int> son;son.pb(-1);
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        son.pb(e[i].to);G[e[i].to] = std::max(G[e[i].to],G[v]+1);
    }
    int m = (int)son.size()-1;
    pre[0] = suf[m+1] = 0;
    FOR(i,1,m) pre[i] = std::max(pre[i-1],F[son[i]]+2);
    ROF(i,m,1) suf[i] = std::max(suf[i+1],F[son[i]]+2);
    FOR(i,1,m) G[son[i]] = std::max({G[son[i]],pre[i-1],suf[i+1]});
    son.clear();
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        down(e[i].to,v);
    }
}

const int MAXM = 16;
int f[MAXN][MAXM+1],dfn[MAXN],sz[MAXN],ts;
P leaf[MAXN];

inline void dfs(int v,int fa=0){
    dfn[v] = ++ts;sz[v] = 1;dep[v] = dep[fa]+1;
    f[v][0] = fa;FOR(i,1,MAXM) f[v][i] = f[f[v][i-1]][i-1];
    leaf[v] = MP(0,v);
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs(e[i].to,v);sz[v] += sz[e[i].to];
        leaf[v] = std::max(leaf[v],MP(leaf[e[i].to].fi+1,leaf[e[i].to].se));
    }
}

inline int getkth(int x,int k){
    FOR(i,0,MAXM) if((k>>i)&1) x = f[x][i];
    return x;
}

inline bool pd(int x,int y){
    return (dfn[x] >= dfn[y] && dfn[x] <= dfn[y]+sz[y]-1) || (dfn[y] >= dfn[x] && dfn[y] <= dfn[x]+sz[x]-1);
}
int T;
inline void Solve(){ts = 0;
    scanf("%d%d%d",&n,&a,&b);
    FOR(i,1,n) head[i] = F[i] = G[i] = dfn[i] = sz[i] = 0;cnt = 0;
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);add(u,v);
    }
    up(1);down(1);
    int len = 0,u = a,v = b;
    while(u != v){
        if(dep[u] < dep[v]) std::swap(u,v);
        len++;u = fa[u];
    }
    int rt = -1;
    FOR(v,1,n){
        int t = 0;
        for(int i = head[v];i;i = e[i].nxt){
            if(e[i].to == fa[v]) continue;
            if(F[e[i].to]+1 >= len) ++t;
        }
        if(G[v] >= len) ++t;
        if(t >= 3){
            rt = v;break;
        }
    }
    if(rt == -1){
        puts("NO");return;
    }
    dfs(rt);int tot = 0;dfn[0] = 0;sz[0] = n+1;
    while(true){
        b = getkth(b,leaf[a].fi);a = leaf[a].se;
        if(pd(a,b)) break;
        std::swap(a,b);++tot;
        if(tot > n){
            puts("NO");return;
        }
    }
    puts("YES");
}

int main(){
    scanf("%d",&T);
    while(T--) Solve();
    return 0;
}