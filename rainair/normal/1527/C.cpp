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
int n;

inline void Solve(){
    scanf("%d",&n);std::vector<P<int,int> > vec;
    FOR(i,1,n){
        int x;scanf("%d",&x);
        vec.pb(x,i);
    }
    std::sort(all(vec));
    LL ans = 0;
    for(int l = 0,r;l < SZ(vec);l = r+1){
        r = l;while(r+1 < SZ(vec) && vec[r+1].fi == vec[l].fi) ++r;
        LL sm = 0;
        FOR(i,l,r){
            ans += (n-vec[i].se+1)*sm;
            sm += vec[i].se;
        }
    }
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}