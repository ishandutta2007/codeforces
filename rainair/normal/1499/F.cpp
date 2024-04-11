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

const int MAXN = 5000+5;
const int ha = 998244353;
int n,k;
std::vector<int> G[MAXN];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int f[MAXN][MAXN],sz[MAXN],tmp[MAXN];

inline void merge(int x,int y){
    FOR(i,0,sz[x]+sz[y]) tmp[i] = 0;
    FOR(i,0,std::min(k,sz[x])){
        FOR(j,0,std::min(k,sz[y])){
            if(i+j+1 <= k) add(tmp[std::max(i,j+1)],1ll*f[x][i]*f[y][j]%ha);
            add(tmp[i],1ll*f[x][i]*f[y][j]%ha);
        }
    }
    FOR(i,0,sz[x]+sz[y]) f[x][i] = tmp[i];
    sz[x] += sz[y];
}

inline void dfs(int v,int fa=0){
    sz[v] = 1;f[v][0] = 1;
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v);
        merge(v,x);
    }
}

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    dfs(1);
    int ans = 0;
    FOR(i,0,n-1) add(ans,f[1][i]);
    printf("%d\n",ans);
    return 0;
}