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

int n;
std::vector<int> G[MAXN];
LL ans[MAXN];
int dep[MAXN],sz[MAXN],sm[MAXN];

inline void dfs(int v,int fa=0){
    dep[v] = dep[fa]+1;sz[v] = 1;
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v);sz[v] += sz[x];
    }
}

bool flag;
int lim;

inline void dfs1(int v,int fa=0){
    sm[v] = (v <= lim);
    int c = 0;
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs1(x,v);
        sm[v] += sm[x];
        if(sm[x]) ++c;
    }
    flag &= (c <= 1);
}

inline bool chk(int x){
    int ps = 1;
    FOR(i,2,n) if(i <= x && dep[i] > dep[ps]) ps = i;
    flag = 1;lim = x;
    dfs1(ps);
    return flag;
}

int col[MAXN];

inline void dfs2(int v,int d,int fa=0){
    col[v] = d;
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs2(x,d,v);
    }
}

inline void Solve(){
    scanf("%d",&n);
    FOR(i,0,n) G[i].clear(),ans[i] = 0,col[i] = 0;
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);
        ++u;++v;G[u].pb(v);G[v].pb(u);
    }
    dfs(1);
    ans[0] = 1ll*n*(n-1)/2;
    int l = 1,r = n,res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) res = mid,l = mid+1;
        else r = mid-1;
    }
    FOR(i,res+1,n) ans[i] = 0;
    lim = res;dfs1(1);
    int t = 0;
    int S[3];
    ans[1] = ans[0];
    for(auto x:G[1]){
        ans[1] -= 1ll*sz[x]*(sz[x]-1)/2;
        if(sm[x]){
            ++t;S[t] = sz[x];
            dfs2(x,t,1);
        }
    }
    assert(t <= 2);
    {
    int r[3];r[1] = r[2] = 1e9; 
    FOR(i,2,res){
        r[col[i]] = std::min(r[col[i]],sz[i]);
        if(r[1] != 1e9 && r[2] != 1e9) ans[i] = 1ll*r[1]*r[2];
        else{
            int R = (r[1] == 1e9 ? n-S[2] : n-S[1]);
            ans[i] = 1ll*std::min(r[1],r[2])*R;
        }
    }
    }
    FOR(i,0,n-1) ans[i] -= ans[i+1];
    FOR(i,0,n) printf("%lld%c",ans[i]," \n"[i==n]);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}