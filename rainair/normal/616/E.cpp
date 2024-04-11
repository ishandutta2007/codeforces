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

LL n,m;
const int ha = 1e9 + 7;

inline LL calc(LL n){
    LL x = n,y = n+1;
    if(x&1) y >>= 1;
    else x >>= 1;
    return (x%ha)*(y%ha)%ha;
}

int main(){
    scanf("%lld%lld",&n,&m);
    LL res = (n%ha)*(m%ha)%ha;
    m = std::min(m,n);
    for(LL l = 1,r;l <= m;l = r+1){
        r = std::min(m,n/(n/l));
        (res += ha-(n/l)%ha*(calc(r)-calc(l-1)+ha)%ha) %= ha;
    }
    printf("%lld\n",res);
    return 0;
}