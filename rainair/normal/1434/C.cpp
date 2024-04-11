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
        LL a,b,c,d;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a > c*b){
            puts("-1");
            continue;
        }
        if(d >= c){
            printf("%lld\n",a);
            continue;
        }
        LL t = ((a-1)/b)/d;
        printf("%lld\n",(t+1)*a-t*(t+1)/2*b*d);
    }
    return 0;
}