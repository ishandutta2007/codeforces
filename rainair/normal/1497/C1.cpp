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
        LL n,k;scanf("%lld%lld",&n,&k);
        int t = k-3;
        n -= t;
        FOR(i,1,t) printf("%d ",1);
        if(n&1){
            printf("%lld %lld %d",n/2,n/2,1);
        }
        else{
            if(n%4 == 2){
                printf("%lld %lld %d",(n-2)/2,(n-2)/2,2);
            }
            else{
                printf("%lld %lld %lld",n/2,n/4,n/4);
            }
        }
        puts("");
    }
    return 0;
}