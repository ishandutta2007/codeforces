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

int main(){
    int T;scanf("%d",&T);
    while(T--){
        LL x,y;scanf("%lld%lld",&x,&y);
        y = std::min(y,x-1);
        LL ans = 0;
        LL q = std::sqrt(1.0*x);
        FOR(i,1,std::min(q,y)){
            ans += (1ll*i*i)/(i+1);
        }
        //[q+1,y]
        if(q+1 < y+1){
            for(int l = q+2,r;l <= y+1;l = r+1){
                r = std::min(y+1,x/(x/l));
                ans += (r-l+1)*(x/l);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}