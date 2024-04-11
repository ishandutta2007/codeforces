#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
LL t[MAXN],x[MAXN];
int n;

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lld%lld",t+i,x+i);
    LL now = 0,rem = 0,d = 0;t[n+1] = 1e18;
    int ans = 0;
    FOR(i,1,n){
        if(!rem){
            d = x[i] < now ? -1 : 1;
            rem = std::abs(x[i]-now);
            if(rem <= t[i+1]-t[i]){
                ans++;
            }
        }
        else{
            LL l = now,r = now+std::min(t[i+1]-t[i],rem)*d;
            if(l > r) std::swap(l,r);
            ans += (l <= x[i] && x[i] <= r);
        }
        if(rem){
            LL tt = std::min(t[i+1]-t[i],rem);
            now += d*tt;
            rem -= tt;
        }
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}