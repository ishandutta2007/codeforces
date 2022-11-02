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

int n;LL k;
const int MAXN = 1e5 + 5;
const int MAX = 50;
LL f[MAXN],s[MAXN];
bool vis[MAXN];

inline LL pw(int n){
    if(n >= 60) return 2e18;
    return 1ll<<n;
}

inline void Solve(){
    scanf("%d%lld",&n,&k);
    if(n <= 60){
        if(k > (1ll<<(n-1))){
            puts("-1");
            return;
        }
    }
    FOR(i,1,n) vis[i] = 0;
    FOR(i,1,n-1){// (i,i+1)?
        if(k <= pw(n-i-1)){
            vis[i] = 1;
            continue;
        }
        k -= pw(n-i-1);
//        vis[i] = 1;
    }
    std::vector<int> tmp;
    FOR(i,1,n){
        tmp.pb(i);
        if(vis[i]){
            std::reverse(all(tmp));
            for(auto x:tmp) printf("%d ",x);
            tmp.clear();
        }
    }
    std::reverse(all(tmp));
    for(auto x:tmp) printf("%d ",x);
    tmp.clear();puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}