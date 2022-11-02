/*
 * Author: RainAir
 * Time: 2020-03-05 10:40:41
 */
#include<bits/stdc++.h>

#define fi first
#define se second
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
#define int LL
inline int phi(int n){
    int q = std::sqrt(1.0*n);
    int ans = n;
    FOR(i,2,q){
        if(!(n%i)){
            while(!(n%i)) n /= i;
            ans = ans/i*(i-1);
        }
    }
    if(n > 1) ans = ans/n*(n-1);
    return ans;
}

inline int gcd(int x,int y){
    return !y ? x : gcd(y,x%y);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--){
        int a,m;scanf("%lld%lld",&a,&m);
        int g = gcd(a,m);
        printf("%lld\n",phi(m/g));
    }
    return 0;
}