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

const int MAXN = 5e5 + 5;
std::vector<int> G[MAXN];
int n;
int dep[MAXN];
std::vector<int> S;

inline void dfs(int v,int fa=0){
    dep[v] = dep[fa]+1;
    if(G[v].size() == 1) S.pb(dep[v]);
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v);
    }
}

int cnt[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    int ans = 0;
    for(auto x:G[1]){
        S.clear();
        dfs(x,1);
        std::sort(all(S));
        FOR(i,0,SZ(S)-1){
            ans = std::max(ans,S[i]+SZ(S)-i-1);
        }
    }
    printf("%d\n",ans);
    return 0;
}