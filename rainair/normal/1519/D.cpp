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
int n,a[MAXN],b[MAXN];
LL f[MAXN][MAXN],pre[MAXN],suf[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) scanf("%d",b+i);
    FOR(i,1,n) pre[i] = pre[i-1]+1ll*a[i]*b[i];
    ROF(i,n,1) suf[i] = suf[i+1]+1ll*a[i]*b[i];
    FOR(i,1,n) f[i][i] = 1ll*a[i]*b[i];
    FOR(len,2,n){
        FOR(l,1,n-len+1){
            int r = l+len-1;
            f[l][r] = f[l+1][r-1]+1ll*a[l]*b[r]+1ll*a[r]*b[l];
        }
    }
    LL ans = 0;FOR(i,1,n) ans += 1ll*a[i]*b[i];
    FOR(l,1,n){
        FOR(r,l,n){
            ans = std::max(ans,pre[l-1]+suf[r+1]+f[l][r]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}