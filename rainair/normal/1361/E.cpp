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

const int MAXN = 2e5 + 5;

int n,m;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
}

bool ins[MAXN];
bool vis[MAXN];

inline bool dfs1(int v){
    vis[v] = ins[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(!vis[e[i].to]) {if(!dfs1(e[i].to)) return 0;}
        else if(!ins[e[i].to]) return 0;
    }
    ins[v] = 0;
    return 1;
}

inline bool chk(int x){
    FOR(i,1,n) vis[i] = ins[i] = 0;
    return dfs1(x);
}

std::mt19937 g(time(NULL));
int sz[MAXN],low[MAXN],dep[MAXN];

inline void dfs2(int v){
    vis[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(!vis[e[i].to]){
            dep[e[i].to] = dep[v]+1;
            dfs2(e[i].to);
            sz[v] += sz[e[i].to];
            if(dep[low[v]] > dep[low[e[i].to]]) low[v] = low[e[i].to];
        }
        else{
            sz[v]++;sz[e[i].to]--;
            if(dep[low[v]] > dep[e[i].to]) low[v] = e[i].to;
        }
    }
}

bool f[MAXN];

inline void dfs3(int v){
    if(sz[v] == 1 && f[low[v]]){
        f[v] = 1;
    }
    for(int i = head[v];i;i = e[i].nxt){
        if(dep[e[i].to] > dep[v]) dfs3(e[i].to);
    }
}

inline void Solve(){
    scanf("%d%d",&n,&m);FOR(i,1,n) head[i] = 0;cnt = 0;
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);add(u,v);
    }
    std::vector<int> v;FOR(i,1,n) v.pb(i);std::shuffle(all(v),g);
    int r = -1;
    FOR(i,1,std::min(50,n)) if(chk(v[i-1])){r=v[i-1];break;}
    if(r == -1){
        puts("-1");return;
    }
    FOR(i,1,n) vis[i] = ins[i] = sz[i] = dep[i] = low[i] = 0;
    dep[r] = 1;dep[0] = n;dfs2(r);
    FOR(i,1,n) f[i] = 0;int tot = 0;
    f[r] = 1;dfs3(r);FOR(i,1,n) tot += f[i];
    if(tot*5 < n) printf("-1");
    else FOR(i,1,n) if(f[i]) printf("%d ",i);
    puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}