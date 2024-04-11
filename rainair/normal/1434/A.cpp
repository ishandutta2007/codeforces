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
#define int LL
const int MAXN = 1e5 + 5;
LL a[MAXN],b[MAXN];
int n;

inline void Solve(){
    FOR(i,1,6) scanf("%lld",a+i);
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",b+i);
    std::sort(b+1,b+n+1);std::sort(a+1,a+7);
    LL ans = 1e18;
    FOR(i,1,n){
        FOR(j,1,6){ // 
            int l = b[i]-a[j],r = -1e18;
            bool flag = 1;
            FOR(k,1,6){
                int p = std::lower_bound(b+1,b+n+1,l+a[k])-b-1;
                if(k == 1){
                    if(p){flag = 0;break;}
                    else continue;
                }
                if(b[p]-a[k-1] < l) continue;
                r = std::max(r,b[p]-a[k-1]);
            }
            if(!flag) continue;
            ans = std::min(ans,std::max(r,b[n]-a[6])-l);
        }
    }
    printf("%lld\n",ans);

}

signed main(){
    int T = 1;
    while(T--) Solve();
    return 0;
}