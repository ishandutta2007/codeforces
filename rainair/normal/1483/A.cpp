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

const int MAXN = 1e5 + 5;
std::vector<int> G[MAXN];int n,m;
int cnt[MAXN],ans[MAXN],cc[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&m);FOR(i,1,n) cnt[i] = 0;
    FOR(i,1,m){
        G[i].clear();
        int sz;scanf("%d",&sz);
        while(sz--){
            int x;scanf("%d",&x);
            G[i].pb(x);++cnt[x];
        }
    }
    FOR(i,1,n) cc[i] = 0;
    std::vector<int> vec;
    FOR(i,1,m){
        int ps = -1;
        for(auto x:G[i]){
            if(cnt[x] <= (m+1)/2){ps = x;break;}
        }
        if(ps != -1) ans[i] = ps;
        else{
            vec.pb(i);
        }
    }
    for(auto v:vec){
        if(SZ(G[v]) == 1) ans[v] = G[v][0],++cc[G[v][0]];
    }
    for(auto v:vec){
        if(SZ(G[v]) == 1) continue;
        int ps = *std::min_element(all(G[v]),[&](int x,int y){return cc[x] < cc[y];});
        ans[v] = ps;++cc[ps];
    }
   // FOR(i,1,m) DEBUG(ans[i]);
    int tmp = *std::max_element(cc+1,cc+n+1);
    if(tmp > (m+1)/2){
        puts("NO");
    }
    else{
        puts("YES");
        FOR(i,1,m) printf("%d ",ans[i]);puts("");
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}