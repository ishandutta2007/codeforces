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

inline void Solve(){
    LL a,b,c,d;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(a <= b){
        printf("%lld\n",b);
        return;
    }
    if(c <= d){
        puts("-1");
        return;
    }
    printf("%lld\n",b+1ll*c*(LL)std::ceil(1.0*(a-b)/(c-d)));
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}