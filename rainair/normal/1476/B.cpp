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
LL a[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,k;scanf("%d%d",&n,&k);
        FOR(i,1,n) scanf("%lld",a+i),a[i] *= 100;
        LL s = a[1]/100,mx = 0;
        FOR(i,2,n){
            mx = std::max(mx,a[i]-s*k);
            s += a[i]/100;
        }
        if(mx<=0){
            puts("0");
            continue;
        }
        LL ans = (mx+k-1)/k;
        printf("%lld\n",ans);
    }
    return 0;
}