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
        int n,k1,k2,w,b;
        scanf("%d%d%d%d%d",&n,&k1,&k2,&w,&b);
        auto calc = [&](int x,int y){
            if(x > y) std::swap(x,y);
            return x + (y-x)/2;
        };
        int mx1 = calc(k1,k2),mx2 = calc(n-k1,n-k2);
        puts(w <= mx1 && b <= mx2?"YES":"NO");
    }
    return 0;
}