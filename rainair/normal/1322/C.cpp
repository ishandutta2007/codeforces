#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

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
#define int LL
const int MAXN = 5e5 + 5;

int a[MAXN],n,m;
std::vector<int> G[MAXN];
std::map<std::vector<int>,LL> S;

inline LL gcd(LL a,LL b){
    return !b ? a : gcd(b,a%b);
}

inline void Solve(){
    scanf("%lld%lld",&n,&m);
    FOR(i,1,n) scanf("%lld",a+i),G[i].clear();
    FOR(i,1,m){
        int u,v;scanf("%lld%lld",&u,&v);
        G[v].pb(u);
    }S.clear();
    FOR(i,1,n) std::sort(all(G[i]));
    FOR(i,1,n){
        if(G[i].empty()) continue;
        S[G[i]] += a[i];
    }
    LL ans = 0;
    for(auto x:S) ans = std::__gcd(x.se,ans);
    printf("%lld\n",ans);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}