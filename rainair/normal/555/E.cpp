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

const int MAXN = 300000+5;
struct Edge{
    int to,next;
}e1[MAXN<<1],e2[MAXN<<1];
int head1[MAXN],head2[MAXN],cnt1 = 1,cnt2 = 1,bel[MAXN];
int low[MAXN],dfn[MAXN],st[MAXN],top,block;
int N,M,Q;int f[MAXN][50],dep[MAXN],par[MAXN],up[MAXN],down[MAXN];
bool ins[MAXN];

inline int find(int x){
    return x == par[x] ? x : par[x] = find(par[x]);
}

inline bool Union(int x,int y){
    int fx = find(x),fy = find(y);
    if(fx == fy) return false;
    par[fy] = fx;return true;
}

inline void add1(int u,int v){
    e1[++cnt1] = (Edge){v,head1[u]};head1[u] = cnt1;
}

inline void add2(int u,int v){
    e2[++cnt2] = (Edge){v,head2[u]};head2[u] = cnt2;
}
//int ts = 0;
inline void dfs1(int v,int fa){
    static int ts = 0;
    dfn[v] = low[v] = ++ts;st[++top] = v;ins[v] = true;
    for(int i = head1[v];i;i = e1[i].next){
        if(i != fa){
            // DEBUG(e1[i].to);
            if(!dfn[e1[i].to]){
                dfs1(e1[i].to,i^1);
                low[v] = std::min(low[v],low[e1[i].to]);
            }
            else if(ins[e1[i].to]) low[v] = std::min(low[v],dfn[e1[i].to]);
        }
    }
    if(dfn[v] != low[v]) return;
    block++;int r = -1;
    while(r != v){
        r = st[top--];ins[r] = false;bel[r] = block;
    }
}

inline void rebuild(){
    FOR(v,1,N){
        for(int i = head1[v];i;i = e1[i].next){
            if(bel[v] != bel[e1[i].to]){
                if(Union(bel[v],bel[e1[i].to]))
                    add2(bel[v],bel[e1[i].to]),
                    add2(bel[e1[i].to],bel[v]);
            }
        }
    }
}

float log2N;

void dfs2(int v,int fa){
    FOR(i,1,log2N){
        if(dep[v] <= (1<<i)) break;
        f[v][i] = f[f[v][i-1]][i-1];
    }
    for(int i = head2[v];i;i = e2[i].next){
        if(e2[i].to == fa) continue;
        //DEBUG(v);DEBUG(e2[i].to);
        dep[e2[i].to] = dep[v] + 1;
        f[e2[i].to][0] = v;
        dfs2(e2[i].to,v);
    }
}

int lca(int x,int y){
    int dx = dep[x],dy = dep[y];
    if(dx != dy){
        if(dx < dy) std::swap(x,y),std::swap(dx,dy);
        int d = dx-dy;
        FOR(i,0,log2N) if((1<<i)&d) x = f[x][i];
    }
    if(x == y) return x;
    ROF(i,log2N,0){
        if(f[x][i] == f[y][i]) continue;
        x = f[x][i],y = f[y][i];
    }
    return f[x][0];
}

bool ans;

void dfs3(int v){
    if(!ans) return;
    for(int i = head2[v];i;i = e2[i].next){
        if(dep[e2[i].to] > dep[v]){
            dfs3(e2[i].to);
            if(!ans) return;
            up[v] += up[e2[i].to];down[v] += down[e2[i].to];
        }
    }
    if(up[v] && down[v]) ans = false;
}

int main(){
    scanf("%d%d%d",&N,&M,&Q);
    FOR(i,1,N) par[i] = i;
    FOR(i,1,M){
        int u,v;scanf("%d%d",&u,&v);
        add1(u,v);add1(v,u);
    }
    FOR(i,1,N) if(!dfn[i]) dfs1(i,0);
    //FOR(u,1,N) printf("%d %d\n",low[u],dfn[u]);
    rebuild();log2N = log2(1.0*block);CLR(f,-1);
    FOR(v,1,block){
        if(find(v) == v) dep[v] = 1,dfs2(v,0);
    }
    // FOR(i,1,N) printf("%d ",dep[i]);puts("");
    ans = true;
    FOR(i,1,Q){
        int u,v;scanf("%d%d",&u,&v);
        u = bel[u],v = bel[v];
        if(u == v) continue;
        if(find(u) != find(v)){
            ans = false;break;
        }
        int l = lca(u,v);// DEBUG(l);
        up[u]++;down[v]++;up[l]--;down[l]--;
    }
    if(ans) FOR(i,1,block){
        if(i == find(i)) dfs3(i);
        if(!ans) break;
    }
    //FOR(i,1,N) printf("%d %d\n",up[i],down[i]);
    puts(ans ? "Yes" : "No");
    return 0;
}