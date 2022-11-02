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

const int MAXN = 1e5 + 5;
#define int LL

std::vector<int> G[MAXN];
int n,s[MAXN],a[MAXN];
int f[MAXN];

inline void dfs1(int v){
    if(s[v] == -1) s[v] = 1e9+114514;
    s[f[v]] = std::min(s[f[v]],s[v]);
    for(auto x:G[v]){
        dfs1(x);
    }
}

inline void dfs(int v,int d=1){
    int t = f[v];
    if(s[t] > s[v]){
        puts("-1");
        exit(0);
    }
    if(s[v] != 1e9+114514) a[v] = s[v]-s[t];
    for(auto x:G[v]){
        if(x == f[v]) continue;
        dfs(x,d+1);
    }
}

signed main(){
    scanf("%lld",&n);
    FOR(i,2,n){
        scanf("%lld",f+i);G[f[i]].pb(i);
    }
    FOR(i,1,n) scanf("%lld",s+i);
    dfs1(1);dfs(1);
    int ans = 0;
    FOR(i,1,n) ans += a[i];
    printf("%lld\n",ans);
    return 0;
}