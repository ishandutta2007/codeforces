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

const int MAXN = 5000+5;
int n,t[MAXN],s[MAXN];
LL f[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",t+i);
        FOR(i,1,n) scanf("%d",s+i);
        FOR(i,1,n) f[i] = 0;
        ROF(i,n,1){
            FOR(j,1,i-1){
                LL ti = f[i],tj = f[j],c = std::abs(s[i]-s[j]);
                if(t[i] == t[j]) continue;
                f[i] = std::max(f[i],tj+c);
                f[j] = std::max(f[j],ti+c);
            }
        }
        LL ans = 0;
        FOR(i,1,n) ans = std::max(ans,f[i]);
        printf("%lld\n",ans);
    }
    return 0;
}