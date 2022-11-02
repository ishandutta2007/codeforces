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

const int MAXN = 5e5 + 5;
std::vector<int> G[MAXN],S[MAXN];
int n,m,f[MAXN];bool vis[MAXN];
std::vector<int> res;

inline void dfs(int v,int d=1){
    vis[v] = 1;S[d].pb(v);
    for(auto x:G[v]){
        if(vis[x]) continue;
        f[x] = v;dfs(x,d+1);
    }
}

inline void Solve(){
    scanf("%d%d",&n,&m);int lim = (n+1)/2;
    FOR(i,1,n) vis[i] = 0,G[i].clear(),S[i].clear();
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    dfs(1);
    if(!S[lim].empty()){
        puts("PATH");
        printf("%d\n",lim);
        int x = S[lim][0];
        while(x){
            printf("%d ",x);
            x = f[x];
        }
        puts("");
        return;
    }
    puts("PAIRING");
    std::vector<P<int,int> > res;
    FOR(i,1,n){
        if(S[i].empty()) break;
        for(int j = 1;j < SZ(S[i]);j += 2) res.pb(S[i][j-1],S[i][j]);
    }
    printf("%d\n",SZ(res));
    for(auto x:res) printf("%d %d\n",x.fi,x.se);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}