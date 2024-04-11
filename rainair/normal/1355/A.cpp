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

inline int mn(LL x){
    int res = 1e9;
    while(x) res = std::min(1ll*res,x%10),x /= 10;
    return res;
}

inline int mx(LL x){
    int res = -1e9;
    while(x) res = std::max(1ll*res,x%10),x /= 10;
    return res;
}

inline void Solve(){
    LL a,k;scanf("%lld%lld",&a,&k);--k;
    while(k--){
        if(mn(a) == 0) break;
        a += mn(a)*mx(a);
    }
    printf("%lld\n",a);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}