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
int f[MAXN],a[MAXN],n;
std::vector<int> G[MAXN];
LL sm[MAXN],ans[MAXN];

inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) G[i].clear();
    FOR(i,1,n) scanf("%d",f+i);
    FOR(i,1,n) scanf("%d",a+i),G[f[i]].pb(a[i]),ans[i] = 0;
    FOR(i,1,n){
        std::sort(all(G[i]));std::reverse(all(G[i]));
        FOR(j,1,SZ(G[i])) sm[j] = sm[j-1]+G[i][j-1];
        FOR(j,1,SZ(G[i])){
            ans[j] += sm[(SZ(G[i])/j)*j];
        }
    }
    FOR(i,1,n) printf("%lld%c",ans[i]," \n"[i==n]);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}