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

const int MAXN = 4e5 + 5;

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt,deg[MAXN];

inline void add(int u,int v,int w){
    ++deg[u];++deg[v];
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

std::map<P<LL,LL>,int> S;
int n;

inline int get(P<LL,LL> x){
    LL g = std::__gcd(x.fi,x.se);
    x.fi /= g;x.se /= g;
    if(!S.count(x)) S[x] = SZ(S)+1;
    return S[x];
}

std::vector<P<int,int> > ans;
bool vis[MAXN];int dep[MAXN];

inline int dfs(int v,int fe=0){
    vis[v] = 1;std::vector<int> vec;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].w == fe) continue;
        if(!vis[e[i].to]){
            dep[e[i].to] = dep[v] + 1;
            int t = dfs(e[i].to,e[i].w);
            if(t) vec.pb(t);
        }
        else{
            if(dep[e[i].to] < dep[v]) vec.pb(e[i].w);
        }
    }
    if(fe) vec.pb(fe);
    for(int i = 1;i < SZ(vec);i += 2) ans.pb(vec[i-1],vec[i]);
    if(SZ(vec)&1) return vec.back();
    else return 0;
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
        // x = a/b,y = c/d
        // y/x = bc/ad
        // (y+1)/x = b(c+d)/ad
        // y/(x+1) = bc/(a+b)d
        add(get(MP(1ll*b*(c+d),1ll*a*d)),get(MP(1ll*b*c,1ll*(a+b)*d)),i);
    }
    n = SZ(S);
    FOR(i,1,n) if(!vis[i]) dep[i] = 1,dfs(i);
    printf("%d\n",SZ(ans));
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
    return 0;
}