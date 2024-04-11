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

const int MAXN = 2e5 + 5;
int n;LL a[MAXN];

inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) scanf("%lld",a+i);
    LL ans = 1e18,mn1 = a[1],mn2 = 1e18;
    LL sm = a[1];
    FOR(i,2,n){
        if(i&1) mn1 = std::min(mn1,a[i]);
        else mn2 = std::min(mn2,a[i]);
        sm += a[i];
        ans = std::min(ans,sm+(n-(i+1)/2)*mn1+(n-i/2)*mn2);
    }
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}