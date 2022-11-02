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

const int MAXN = 2e5 + 5;
LL a[MAXN];
int n;

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lld",a+i);
    LL sm = 0;
    FOR(i,2,n) sm += std::abs(a[i]-a[i-1]);
    LL ans = sm;
    ans = std::min(ans,sm-std::abs(a[1]-a[2]));
    ans = std::min(ans,sm-std::abs(a[n]-a[n-1]));
    FOR(i,2,n-1){
        LL t = sm;
        sm -= std::abs(a[i-1]-a[i]);
        sm -= std::abs(a[i]-a[i+1]);
        sm += std::abs(a[i-1]-a[i+1]);
        ans = std::min(ans,sm);
        sm = t;
    }
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}