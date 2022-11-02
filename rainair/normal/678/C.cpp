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

inline LL lcm(LL x,LL y){
    return x*y/std::__gcd(x,y);
}

int main(){
    int n,a,b,p,q;
    scanf("%d%d%d%d%d",&n,&a,&b,&p,&q);
    LL t1 = n/a,t2 = n/b,t3 = n/lcm(a,b);
    t1 -= t3;t2 -= t3;
    LL ans = t1*p+t2*q+t3*std::max(p,q);
    printf("%lld\n",ans);
    return 0;
}