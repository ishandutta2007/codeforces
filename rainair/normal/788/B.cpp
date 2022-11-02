#include<bits/stdc++.h>

#define fi first
#define se second
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

const int MAXN = 5e6 + 5;
int du[MAXN];
int n,m,h;
bool vis[MAXN];
std::vector<int> G[MAXN];

inline void dfs(int v){
    vis[v] = 1;
    for(auto x:G[v]){
        if(!vis[x]) dfs(x);
    }
}
bool hs[MAXN];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        if(u == v) h++;
        else du[u]++,du[v]++;
        G[u].pb(v);G[v].pb(u);
        hs[u] = hs[v] = 1;
    }
    FOR(i,1,n) if(hs[i]){dfs(i);break;}
    FOR(i,1,n) if(hs[i] && !vis[i]){puts("0");return 0;}
    LL ans = 0;
    // case 1
    FOR(i,1,n) ans += 1ll*du[i]*(du[i]-1)/2;
//    DEBUG(ans);
    // case 2
    ans += 1ll*h*(m-h)+1ll*h*(h-1)/2;
//    FOR(i,1,n) ans += 1ll*h*du[i];
    printf("%lld\n",ans);
    return 0;
}