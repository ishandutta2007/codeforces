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

int n,q;
LL a[MAXN];
// >= x 

inline void Solve(){
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%lld",a+i),a[i] += a[i-1];
    std::vector<P<LL,int> > S;
    LL now = -1e18;
    FOR(i,1,n){
        if(a[i] <= now) continue;
        S.pb(a[i],i);
        now = a[i];
    }
    LL mx = *std::max_element(a+1,a+n+1);
    std::sort(all(S));
    while(q--){
        LL x;scanf("%lld",&x);
        auto p = std::lower_bound(all(S),MP(x,-1));
        if(p != S.end()) printf("%d ",p->se-1);
        else{
            if(a[n] <= 0){
                printf("-1 ");
                continue;
            }
            auto calc = [&](LL ps) -> LL{
                if(ps<=0) return 1e18;
                auto p = std::lower_bound(all(S),MP(x-(ps-1)*a[n],-1));
                if(p == S.end()) return 1e18;
                return (ps-1)*n+p->se;
            };
            LL ps = (x-mx+a[n]-1)/a[n];++ps;
            LL ans = ps*n;
            FOR(i,-2,2) ans = std::min(ans,calc(ps+i));
            ans--;
            printf("%lld ",ans);
        }
    }
    puts("");
}

int main(){
#ifdef RainAir
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
#endif
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}