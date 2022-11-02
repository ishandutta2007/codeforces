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
    LL h1,h2,a,b;
    scanf("%lld%lld%lld%lld",&h1,&h2,&a,&b);
    LL now = h1+8*a;
    if(now >= h2){
        puts("0");
        return 0;
    }
    now -= 12*b;
    FOR(i,1,100000){
        if(now+12*a >= h2){
            printf("%d\n",i);
            return 0;
        }
        now += 12*a;
        now -= 12*b;
    }
    puts("-1");
    return 0;
}