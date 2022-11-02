#include <bits/stdc++.h>

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
#define int LL
const int MAXN = 2e5 + 5;
int t[MAXN],h[MAXN],n;
int in[MAXN],out[MAXN];

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int f[MAXN],g[MAXN];
// f: 
// g: 
bool vis[MAXN];
int sm[MAXN];

inline void dfs(int v,int fa=0){
    int sz = 0;int smg = 0;vis[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs(e[i].to,v);
    }
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        sm[++sz] = f[e[i].to]-g[e[i].to];
        smg += g[e[i].to];
    }
    std::sort(sm+1,sm+sz+1);std::reverse(sm+1,sm+sz+1);
    FOR(i,1,sz) sm[i] += sm[i-1];
    out[v] += (bool)(fa);
    FOR(i,0,sz){
        f[v] = std::max(f[v],smg+sm[i]+std::min(in[v]+i,out[v]+sz-i)*t[v]);
    }
    out[v] -= (bool)(fa);
    in[v] += (bool)(fa);
    FOR(i,0,sz){
        g[v] = std::max(g[v],smg+sm[i]+std::min(in[v]+i,out[v]+sz-i)*t[v]);
    }
    in[v] -= (bool)(fa);
    FOR(i,0,sz) sm[i] = 0;
}

int F[MAXN],G[MAXN],tot;
int deg[MAXN];

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",t+i);
    FOR(i,1,n) scanf("%lld",h+i);
    FOR(i,2,n){
        int u,v;scanf("%lld%lld",&u,&v);deg[u]++;deg[v]++;
        if(h[u] > h[v]) std::swap(u,v);
        if(h[u] == h[v]) add(u,v);
        else out[u]++,in[v]++;
//        printf("%lld %lld %d\n",u,v,(h[u]==h[v]));
    }
    FOR(i,1,n) if(!vis[i]) dfs(i),F[++tot] = f[i],G[tot] = g[i];
    int ans = 0;
    FOR(i,1,n) ans += deg[i]*t[i];
    FOR(i,1,tot) ans -= F[i];
    printf("%lld\n",ans);
    return 0;
}