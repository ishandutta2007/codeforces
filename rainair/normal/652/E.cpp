#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3e5 + 5;
int n,m;

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt=1;

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

int bel[MAXN],tot;
int dfn[MAXN],low[MAXN];
int st[MAXN],tp;

inline void dfs(int v,int fe=0){
    static int ts = 0;dfn[v] = low[v] = ++ts;
    st[++tp] = v;
    for(int i = head[v];i;i = e[i].nxt){
        if((fe>>1) == (i>>1)) continue;
        if(!dfn[e[i].to]){
            dfs(e[i].to,i);
            low[v] = std::min(low[v],low[e[i].to]);
        }
        else{
            low[v] = std::min(low[v],dfn[e[i].to]);
        }
    }
    if(low[v] == dfn[v]){
        int x=-1;++tot;
        while(x != v){
            x = st[tp--];
            bel[x] = tot;
        }
    }
}

std::vector<P<int,int> > G[MAXN];
bool col[MAXN],vis[MAXN];

inline void dfs1(int v,int fa=0){
    col[v] |= col[fa];
    for(auto x:G[v]){
        if(x.fi == fa) continue;
        col[x.fi] |= x.se;
        dfs1(x.fi,v);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);add(u,v,w);
    }
    int s,t;scanf("%d%d",&s,&t);
    dfs(1);
    FOR(v,1,n){
        for(int i = head[v];i;i = e[i].nxt){
            if(bel[v] != bel[e[i].to]){
                G[bel[v]].pb(MP(bel[e[i].to],e[i].w));
            }
            else{
                col[bel[v]] |= e[i].w;
            }
        }
    }
    dfs1(bel[s]);
    puts(col[bel[t]]?"YES":"NO");
    return 0;
}