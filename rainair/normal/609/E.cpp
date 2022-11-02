#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int n,m;

struct Edge{
    int u,v,w,id;
    inline bool operator < (const Edge &t) const {
        return w < t.w;
    }
}e[MAXN];
int F[MAXN];

inline int find(int x){
    return x == F[x] ? x : F[x] = find(F[x]);
}

std::vector<P> G[MAXN];
bool used[MAXN];
const int MAXM = 17;
int f[MAXN][MAXM+1],mx[MAXN][MAXM+1];
LL ans[MAXN],sm = 0;
int dep[MAXN];

inline void dfs(int v,int fa=0){
    dep[v] = dep[fa]+1;
    FOR(i,1,MAXM){
        f[v][i] = f[f[v][i-1]][i-1];
        mx[v][i] = std::max(mx[v][i-1],mx[f[v][i-1]][i-1]);
    }
    for(auto x:G[v]){
        if(x.fi == fa) continue;
        f[x.fi][0] = v;mx[x.fi][0] = x.se;
        dfs(x.fi,v);
    }
}

inline int query(int x,int y){
    int res = 0;
    if(dep[x] != dep[y]){
        if(dep[x] < dep[y]) std::swap(x,y);
        int d = dep[x]-dep[y];
        FOR(i,0,MAXM) if((d>>i)&1) res = std::max(res,mx[x][i]),x = f[x][i];
    }
    if(x == y) return res;
    ROF(i,MAXM,0){
        if(f[x][i] == f[y][i]) continue;
        res = std::max({res,mx[x][i],mx[y][i]});
        x = f[x][i],y = f[y][i];
    }
    res = std::max({res,mx[x][0],mx[y][0]});
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w),e[i].id = i;std::sort(e+1,e+m+1);
    FOR(i,1,n) F[i] = i;
    FOR(i,1,m){
        int fx = find(e[i].u),fy = find(e[i].v);
        if(fx == fy) continue;
        F[fx] = fy;
        G[e[i].u].pb(MP(e[i].v,e[i].w));
        G[e[i].v].pb(MP(e[i].u,e[i].w));used[i] = 1;sm += e[i].w;
    }
    dfs(1);
    FOR(i,1,m){
        if(used[i]) ans[e[i].id] = sm;
        else ans[e[i].id] = sm+e[i].w-query(e[i].u,e[i].v);
    }
    FOR(i,1,m) printf("%lld\n",ans[i]);
    return 0;
}