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

int n,c[MAXN],a[MAXN],b[MAXN],d[MAXN];
LL s[MAXN],mx[MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n+2) c[i] = a[i] = b[i] = 0;
    FOR(i,1,n) scanf("%d",c+i);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) scanf("%d",b+i);
    FOR(i,1,n-1) d[i] = c[i]-std::abs(a[i+1]-b[i+1])+1;
    FOR(i,1,n) s[i] = d[i]+s[i-1];
    LL ans = 0;
    a[n+1] = -1;b[n+1] = -2;
    for(int l = 1,r;l <= n;l = r+1){
        r = l;while(r+1 <= n && a[r+2] != b[r+2]) ++r;
        mx[l] = std::abs(a[l+1]-b[l+1])+1-s[l];
        FOR(i,l+1,std::min(n,r+1)){
            mx[i] = std::max(mx[i-1],std::abs(a[i+1]-b[i+1])+1-s[i]);
//            DEBUG(mx[i-1]+c[r]+s[r-1]);
            ans = std::max(ans,mx[i-1]+c[i]+s[i-1]);
        }
        //[l,r+1]
    }
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}