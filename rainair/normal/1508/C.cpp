#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
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
    int u,v,w;

    inline bool operator < (const Edge &t) const {
        return w < t.w;
    }
}a[MAXN];
int f[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

inline void merge(int x,int y){
    x = find(x);y = find(y);
    if(x == y) return;
    f[x] = y;
}

std::vector<int> G[MAXN];
int deg[MAXN];

namespace Task1{
    bool vis[MAXN],can[MAXN];
    inline void Solve(){
        int ps = 1;FOR(i,2,n) if(deg[ps] > deg[i]) ps = i;
        FOR(i,1,n) f[i] = i;
        std::vector<int> nd;
        for(auto x:G[ps]) vis[x] = 1;
        FOR(i,1,n){
            if(!vis[i]) merge(i,ps);
            else nd.pb(i);
        }
        FOR(i,1,n) can[i] = vis[i];
        int sm = 0;FOR(i,1,n) sm += !can[i];
        CLR(vis,0);
        FOR(v,1,n){
            int s = 0;
            for(auto x:G[v]) vis[x] = 1,s += !can[x];
            if(s != sm) merge(v,ps);
            for(auto x:nd) if(!vis[x]) merge(x,v);
            for(auto x:G[v]) vis[x] = 0;
        }
        LL ans = 0;
        FOR(i,1,m){
            int u = a[i].u,v = a[i].v;
            if(find(u) == find(v)) continue;
            merge(u,v);ans += a[i].w;
        }
        printf("%lld\n",ans);
    }
}

namespace Task2{
    bool vis[MAXN];
    std::vector<int> T[MAXN];
    std::vector<P<int,int> > vec;
    inline void Solve(){
        int xs = 0;FOR(i,1,m) xs ^= a[i].w;
        FOR(v,1,n){
            FOR(i,v+1,n) vis[i] = 0;
            for(auto x:G[v]) vis[x] = 1;
            FOR(i,v+1,n) if(!vis[i]) vec.pb(v,i);
        }
        LL res = 1e18;
        FOR(c,0,SZ(vec)-1){
            FOR(i,1,n) f[i] = i;
            int xx = vec[c].fi,yy = vec[c].se,ww = xs;
            FOR(i,0,SZ(vec)-1) if(i != c) merge(vec[i].fi,vec[i].se);
            LL ans = 0;
            FOR(i,1,m){
                if(ww != -1 && ww <= a[i].w){
                    if(find(xx) != find(yy)){
                        merge(xx,yy);ans += ww;
                        ww = -1;
                    }
                }
                int x = a[i].u,y = a[i].v,w = a[i].w;
                if(find(x) == find(y)) continue;
                merge(x,y);ans += w;
            }
            if(ww != -1){
                if(find(xx) != find(yy)){
                    merge(xx,yy);ans += ww;
                     ww = -1;
                }
            }
            res = std::min(res,ans);
        }
        printf("%lld\n",res);
    }
}

int main(){
//    freopen("C.in","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
//    FOR(i,1,m) scanf("%d%d",&a[i].u,&a[i].v),a[i].w = 1;
    FOR(i,1,m) ++deg[a[i].u],++deg[a[i].v],G[a[i].u].pb(a[i].v),G[a[i].v].pb(a[i].u);
    std::sort(a+1,a+m+1);
//    Task1::Solve();
//    exit(0);
    if(1ll*n*(n-1)/2-m >= n) Task1::Solve();
    else Task2::Solve();
    return 0;
}