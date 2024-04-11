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

const int MAXN = 1e5 + 5;
int a[MAXN],n;

inline int geth(int x){
    ROF(i,30,0) if((x>>i)&1) return i;
}
int c[35];
inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i);
    CLR(c,0);
    FOR(i,1,n) c[geth(a[i])]++;
    LL ans = 0;
    FOR(i,0,30) ans += 1ll*c[i]*(c[i]-1)/2;
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}