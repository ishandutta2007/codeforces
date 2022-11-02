#include <bits/stdc++.h>

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

int main(){
    int T;scanf("%d",&T);
    while(T--){
        LL p,q;scanf("%lld%lld",&p,&q);
        if(p%q != 0) printf("%lld\n",p);
        else{
            int lim = std::sqrt(1.0*q);
            LL ans = 1,x = q;
            FOR(i,2,lim){
                if(!(x%i)){
                    int e = 0,e2 = 0;
                    while(!(x%i)) ++e,x /= i;
                    LL tt = p;
                    while(!(tt%i)) ++e2,tt /= i;
                    int o = e2-(e-1);
                    tt = p;
                    FOR(j,1,o) tt /= i;
                    ans = std::max(ans,tt);
                }
            }
            if(x != 1){

                    int e = 1,e2 = 0;
                    LL tt = p;
                    while(!(tt%x)) ++e2,tt /= x;
                    int o = e2-(e-1);
                    tt = p;
                    FOR(i,1,o) tt /= x;
                    ans = std::max(ans,tt);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}