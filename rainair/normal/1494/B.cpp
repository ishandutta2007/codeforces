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
        int n,u,r,d,l;
        scanf("%d%d%d%d%d",&n,&u,&r,&d,&l);
        bool flag = 0;
        FOR(S,0,(1<<4)-1){
            int uu = 0,rr = 0,dd = 0,ll = 0;
            if(S&1) ++uu,++ll;
            if((S>>1)&1) ++uu,++rr;
            if((S>>2)&1) ++rr,++dd;
            if((S>>3)&1) ++ll,++dd;
            auto pd = [&](int x,int y){
                return x >= y && x <= y+n-2;
            };
            flag |= pd(u,uu)&&pd(r,rr)&&pd(l,ll)&&pd(d,dd);
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}