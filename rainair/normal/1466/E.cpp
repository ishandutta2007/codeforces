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

const int MAXN = 5e5 + 5;
const int MAXM = 59;
const int ha = 1e9 + 7;

int n;LL a[MAXN];
int cnt[MAXM+1];

inline void Solve(){
    scanf("%d",&n);CLR(cnt,0);
    FOR(i,1,n) scanf("%lld",a+i);
    FOR(i,1,n) FOR(j,0,MAXM) cnt[j] += (a[i]>>j)&1;
    int ans = 0;
    FOR(j,1,n){
        int sm1 = 0,sm2 = 0;
        ROF(i,MAXM,0){
            int c = (1ll<<i)%ha;
            if((a[j]>>i)&1) (sm1 += 1ll*c*cnt[i]%ha) %= ha,(sm2 += 1ll*c*n%ha) %= ha;
            else (sm2 += 1ll*c*cnt[i]%ha) %= ha;
        }
        (ans += 1ll*sm1*sm2%ha) %= ha;
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}