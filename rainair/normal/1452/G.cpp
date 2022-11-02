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

const int MAXN = 2e5 + 5;

std::vector<int> G[MAXN];
int n;bool tag[MAXN];
int f[MAXN],g[MAXN];

inline void dfs1(int v,int fa=0){
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs1(x,v);
        f[v] = std::min(f[v],f[x]+1);
    }
}

int suf[MAXN];

inline void dfs2(int v,int fa=0){
    std::vector<int> son;
    for(auto x:G[v]){
        if(x == fa) continue;
        son.pb(x);g[x] = std::min(g[x],g[v]+1);
        if(tag[v]) g[x] = 1;
    }
    suf[son.size()] = 1e9;
    ROF(i,(int)son.size()-1,0) suf[i] = std::min(suf[i+1],f[son[i]]+1);
    int pre = 1e9;
    FOR(i,0,(int)son.size()-1){
        g[son[i]] = std::min(g[son[i]],std::min(pre,suf[i+1])+1);
        pre = std::min(pre,f[son[i]]+1);
    }
    son.clear();
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs2(x,v);
    }
}

int ans[MAXN],las[MAXN];

inline void dfs(int v,int d,int fa=0,int dep=0){
    if(dep == d) return;
    if(ans[v] < d){
        ans[v] = d;
        las[v] = d-dep;
    }
    else{
        if(las[v] >= d-dep) return;
        else las[v] = d-dep;
    }
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,d,v,dep+1);
    }
}

int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);G[u].pb(v);G[v].pb(u);
    }
    int k;scanf("%d",&k);
    while(k--){
        int x;scanf("%d",&x);tag[x] = 1;
    }
    FOR(i,1,n) f[i] = tag[i] ? 0 : 1e9,g[i] = 1e9;
    dfs1(1);dfs2(1);
    FOR(i,1,n) f[i] = std::min(f[i],g[i]);
    std::vector<P> S;FOR(i,1,n) S.pb(MP(f[i],i));
    std::sort(all(S));std::reverse(all(S));
    for(auto x:S) dfs(x.se,x.fi);
    FOR(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}