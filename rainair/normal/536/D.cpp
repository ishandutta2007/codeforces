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

const int MAXN = 2000+5;
const int MAXM = 1e5 + 5;
int n,m,s,t,p[MAXN];

struct Edge{
    int to,w,nxt;
}e[MAXM<<1];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

LL ds[MAXN],dt[MAXN];
bool used[MAXN];

inline void dij(int s,LL dis[]){
    FOR(i,1,n) used[i] = 0,dis[i] = 1e18;dis[s] = 0;
    FOR(cc,1,n){
        int v = -1;
        FOR(i,1,n) if(!used[i] && (v == -1 || dis[v] > dis[i])) v = i;
        used[v] = 1;
        for(int i = head[v];i;i = e[i].nxt) dis[e[i].to] = std::min(dis[e[i].to],dis[v]+e[i].w);
    }
}

int x[MAXN],y[MAXN];
LL f[MAXN][MAXN][2];//  (i,j) 
LL s1[MAXN][MAXN],s2[MAXN][MAXN];
int sz1[MAXN][MAXN],sz2[MAXN][MAXN];
bool vis[MAXN][MAXN][2];
int N,M;

inline LL dps(int,int);
inline LL dpt(int,int);

inline LL dps(int i,int j){
    if(i == N || j == M) return 0;
    if(vis[i][j][0]) return f[i][j][0];
    vis[i][j][0] = 1;LL &res = f[i][j][0];
    if(sz1[i+1][M]^sz1[i+1][j]) res = std::max(dps(i+1,j),-dpt(i+1,j))+(s1[i+1][M]-s1[i+1][j]);
    else res = dps(i+1,j);
    return res;
}

inline LL dpt(int i,int j){
    if(i == N || j == M) return 0;
    if(vis[i][j][1]) return f[i][j][1];
    vis[i][j][1] = 1;LL &res = f[i][j][1];
    if(sz2[N][j+1]^sz2[i][j+1]) res = std::max(dpt(i,j+1),-dps(i,j+1))+(s2[N][j+1]-s2[i][j+1]);
    else res = dpt(i,j+1);
    return res;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    FOR(i,1,n) scanf("%d",p+i);
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);add(u,v,w);
    }
    dij(s,ds);dij(t,dt);
    std::vector<LL> S;
    FOR(i,1,n) S.pb(ds[i]);std::sort(all(S));S.erase(std::unique(all(S)),S.end());N = S.size();
    FOR(i,1,n) x[i] = std::lower_bound(all(S),ds[i])-S.begin()+1;
    S.clear();FOR(i,1,n) S.pb(dt[i]);std::sort(all(S));S.erase(std::unique(all(S)),S.end());M = S.size();
    FOR(i,1,n) y[i] = std::lower_bound(all(S),dt[i])-S.begin()+1;
    FOR(i,1,n) s1[x[i]][y[i]] += p[i],s2[x[i]][y[i]] += p[i],++sz1[x[i]][y[i]],++sz2[x[i]][y[i]];
    FOR(i,1,N) FOR(j,1,M) s1[i][j] += s1[i][j-1],s2[i][j] += s2[i-1][j],sz1[i][j] += sz1[i][j-1],sz2[i][j] += sz2[i-1][j];
    LL res = dps(0,0);
    if(res > 0) puts("Break a heart");
    else if(res == 0) puts("Flowers");
    else puts("Cry");
    return 0;
}