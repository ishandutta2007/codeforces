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

int main(){
    LL n,b,p;scanf("%lld%lld%lld",&n,&b,&p);
    LL ans1 = 0,ans2 = n*p;
    while(n > 1){
        LL t = 1;
        while((t<<1) <= n) t <<= 1;
        ans1 += (t>>1)*(2*b+1);
        n -= (t>>1);
    }
    printf("%lld %lld\n",ans1,ans2);
    return 0;
}