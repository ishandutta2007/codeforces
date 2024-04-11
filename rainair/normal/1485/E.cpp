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

int n,a[MAXN];
std::vector<int> G[MAXN],S[MAXN];
LL f[MAXN];int now;
int mx[MAXN],mn[MAXN],fa[MAXN];

inline void dfs(int v,int d=1){
    S[d].pb(v);mx[v] = -1e9;mn[v] = 1e9;
    for(auto x:G[v]){
        mx[v] = std::max(mx[v],a[x]);
        mn[v] = std::min(mn[v],a[x]);
        dfs(x,d+1);
    }
}

inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) G[i].clear(),S[i].clear();
    FOR(i,2,n){
        scanf("%d",fa+i);G[fa[i]].pb(i);
    }
    FOR(i,2,n) scanf("%d",a+i);
    dfs(1);FOR(i,1,n) f[i] = -1e18;
    f[1] = 0;int mxd = 1;
    FOR(d,2,n){
        if(S[d].empty()) break;
        mxd = d;
        {
            int mx = -1e9,mn = 1e9;
            for(auto x:S[d]) mx = std::max(mx,a[x]),mn = std::min(mn,a[x]);
            for(auto x:S[d]) f[x] = f[fa[x]]+std::max(a[x]-mn,mx-a[x]);
        }
        std::vector<P<int,LL> > obj,qry;// |x-fi|+se
        for(auto x:S[d-1]){
            obj.pb(mn[x],f[x]);
            obj.pb(mx[x],f[x]);
        }
        for(auto x:S[d]){
            qry.pb(a[x],x);
        }
        std::sort(all(obj));std::sort(all(qry));
        std::multiset<LL> sl,sr;
        for(auto x:obj) sr.insert(x.fi+x.se);
        int p = 0;
        for(auto x:qry){
            while(p < SZ(obj) && obj[p].fi < x.fi){
                sr.erase(sr.find(obj[p].fi+obj[p].se));
                sl.insert(obj[p].se-obj[p].fi);
                ++p;
            }
            if(!sl.empty()) f[x.se] = std::max(f[x.se],*sl.rbegin()+a[x.se]);
            if(!sr.empty()) f[x.se] = std::max(f[x.se],*sr.rbegin()-a[x.se]);
        }
        now ^= 1;
    }
    LL ans = -1e18;
    for(auto x:S[mxd]) ans = std::max(ans,f[x]);
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}