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

const int MAXN = 1e5 + 5;
const int ha = 1e9 + 7;
const int MAXM = 16;
int n,m;

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
    e[++cnt] = {v,w,head[u]};head[u] = cnt;
    e[++cnt] = {u,w,head[v]};head[v] = cnt;
}

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int f[MAXN],f2[MAXN],g[MAXN],g2[MAXN],sz[MAXN],dep[MAXN],sm[MAXN];
int F[MAXN][MAXM+1];
// f: 
// g: 

inline void dfs1(int v,int fa=0){
    sz[v] = 1;dep[v] = dep[fa]+1;
    F[v][0] = fa;
    FOR(i,1,MAXM) F[v][i] = F[F[v][i-1]][i-1];
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        sm[e[i].to] = sm[v]+e[i].w-ha;sm[e[i].to] += sm[e[i].to]>>31&ha;
        dfs1(e[i].to,v);
        add(f[v],f[e[i].to]);
        add(f[v],1ll*sz[e[i].to]*e[i].w%ha);
        add(f2[v],f2[e[i].to]);
        add(f2[v],2ll*e[i].w%ha*f[e[i].to]%ha);
        add(f2[v],1ll*sz[e[i].to]*e[i].w%ha*e[i].w%ha);
        sz[v] += sz[e[i].to];
    }
}

inline void dfs2(int v,int fa=0){
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        g[e[i].to] = g[v];
        add(g[e[i].to],1ll*e[i].w*(n-2*sz[e[i].to]+ha)%ha);
        int h2 = g2[v],h = (g[v]-f[e[i].to]-1ll*sz[e[i].to]*e[i].w%ha+ha+ha)%ha;
        add(h2,ha-f2[e[i].to]);
        add(h2,ha-2ll*e[i].w%ha*f[e[i].to]%ha);
        add(h2,ha-1ll*e[i].w*e[i].w%ha*sz[e[i].to]%ha);
        g2[e[i].to] = f2[e[i].to];
        add(g2[e[i].to],h2);
        add(g2[e[i].to],2ll*e[i].w%ha*h%ha);
        add(g2[e[i].to],1ll*e[i].w*e[i].w%ha*(n-sz[e[i].to])%ha);
        dfs2(e[i].to,v);
    }
}

inline int lca(int x,int y){
    if(dep[x]^dep[y]){
        if(dep[x] < dep[y]) std::swap(x,y);
        int d = dep[x]-dep[y];
        FOR(i,0,MAXM) if((d>>i)&1) x = F[x][i];
    }
    if(x == y) return x;
    ROF(i,MAXM,0){
        if(F[x][i] == F[y][i]) continue;
        x = F[x][i],y = F[y][i];
    }
    return F[x][0];
}

int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    dfs1(1);
    g[1] = f[1];g2[1] = f2[1];
    dfs2(1);
    scanf("%d",&m);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        int l = lca(u,v),d = (sm[u]+sm[v]-2ll*sm[l]%ha+ha+ha)%ha;
        int ans = 0;
        if(l == v){
            ans = g2[u];
            int h = g[v]-f[v],h2 = g2[v]-f2[v];
            h += h>>31&ha;h2 += h2>>31&ha;
            add(ans,ha-h2);
            add(ans,ha-2ll*d*h%ha);
            add(ans,ha-1ll*(n-sz[v])*d%ha*d%ha);
            ans = 2ll*ans%ha;
            add(ans,ha-g2[u]);
        }
        else{
            ans = f2[v];
            add(ans,2ll*d%ha*f[v]%ha);
            add(ans,1ll*d*d%ha*sz[v]%ha);
            ans = 2ll*ans%ha;
            add(ans,ha-g2[u]);
        }
        printf("%d\n",ans);
    }
    return 0;
}