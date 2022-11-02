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
#define U unsigned
#define P std::pair<LL,LL>
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e5 + 5;
std::vector<P> G[MAXN];
std::vector<int> s1,s2;
int n,m,k;
int dis1[MAXN],dis2[MAXN],pre[MAXN];
bool used[MAXN];

struct Edge{
    int u,v,w;

    bool operator < (const Edge &t) const {
        return w < t.w;
    }
};
std::vector<Edge> edge;

inline void dij(std::vector<int> S,int dis[]){
    std::priority_queue<P,std::vector<P>,std::greater<P> > q;
    FOR(i,1,n) dis[i] = LLONG_MAX,used[i] = false;
    for(auto x:S) q.push(MP(dis[x]=0,x)),pre[x] = x;
    while(!q.empty()){
        int v = q.top().se;q.pop();
        if(used[v]) continue;
        used[v] = true;
        for(auto x:G[v]){
            if(dis[x.fi] > dis[v]+x.se){
                dis[x.fi] = dis[v] + x.se;
                pre[x.fi] = pre[v];q.push(MP(dis[x.fi],x.fi));
            }
        }
    }
}

int f[MAXN];
inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

signed main(){
    scanf("%lld%lld",&n,&m);
    FOR(i,1,m){
        int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
        G[u].pb(MP(v,w));G[v].pb(MP(u,w));
    }
    scanf("%lld",&k);s1.pb(1);
    FOR(i,1,k){
        int x;scanf("%lld",&x);
        s2.pb(x);
    }
    dij(s1,dis1);dij(s2,dis2);
    LL ans = LLONG_MAX;
    for(auto x:s2) ans = std::min(ans,dis1[x]);
    FOR(i,1,n) f[i] = i;
    FOR(i,1,n){
        for(auto x:G[i]){
            if(pre[i] != pre[x.fi]) edge.pb((Edge){pre[i],pre[x.fi],dis2[i]+dis2[x.fi]+x.se});
        }
    }
    std::sort(all(edge));
    for(auto x:edge){
        int fu = find(x.u),fv = find(x.v);
        if(fu != fv){
            f[fu] = fv;ans += x.w;
        }
    }
    printf("%lld\n",ans);
    return 0;
}