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

const int MAXN = 8e5 + 5;
std::vector<P<int,int> > G[MAXN];

LL dis[MAXN];bool used[MAXN];
int N;
int pre[MAXN];

inline void dij(int S){
    FOR(i,1,N) used[i] = 0,dis[i] = 1e18;
    std::priority_queue<P<LL,int>,std::vector<P<LL,int> >,std::greater<P<LL,int> > > q;
    q.push(MP(dis[S]=0,S));
    while(!q.empty()){
        LL d;int v;std::tie(d,v) = q.top();q.pop();
        if(d != dis[v] || used[v]) continue;
        used[v] = 1;
        for(auto x:G[v]){
            if(dis[x.fi] > d+x.se){
                dis[x.fi] = d + x.se;
                pre[x.fi] = v;
                q.push(MP(dis[x.fi],x.fi));
            }
        }
    }
}

int n,m;

inline int calc(int x,int i,int j){
    return x+n*(i|(j<<1));
}

inline void add(int u,int v,int w){
    G[u].pb(v,w);
}

int main(){
    scanf("%d%d",&n,&m);N = n*4;
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        FOR(x,0,1) FOR(y,0,1) add(calc(u,x,y),calc(v,x,y),w),add(calc(v,x,y),calc(u,x,y),w);
        FOR(y,0,1) add(calc(u,0,y),calc(v,1,y),0),add(calc(v,0,y),calc(u,1,y),0);
        FOR(x,0,1) add(calc(u,x,0),calc(v,x,1),2*w),add(calc(v,x,0),calc(u,x,1),2*w);
        add(calc(u,0,0),calc(v,1,1),w);
        add(calc(v,0,0),calc(u,1,1),w);
    }
    dij(calc(1,0,0));
    FOR(i,2,n) printf("%lld%c",dis[calc(i,1,1)]," \n"[i==n]);
    return 0;
}