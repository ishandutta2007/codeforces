/*
 * Author: RainAir
 * Time: 2020-05-26 23:54:54
 */
#include<bits/stdc++.h>

#define fi first
#define se second
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
const int MAXN = 5e5 + 5;
int n,x;
int d[MAXN],sm[MAXN],smi[MAXN];
int f[1000000+5];

signed main(){
    scanf("%lld%lld",&n,&x);
    FOR(i,1,n) scanf("%lld",d+i);
    FOR(i,n+1,2*n) d[i] = d[i-n];
    FOR(i,1,2*n) sm[i] = sm[i-1]+d[i],smi[i] = smi[i-1]+d[i]*(d[i]+1)/2;
    FOR(i,1,1e6) f[i] = i;
    FOR(i,1,1e6) f[i] += f[i-1];
    LL ans = -1e18;
    FOR(i,1,2*n){
        int r = sm[i],l = sm[i]-x+1;
        if(l <= 0) continue;
        int t = std::lower_bound(sm+1,sm+i+1,l)-sm;
       // DEBUG(l);DEBUG(r);DEBUG(t);
        int now = smi[i]-smi[t]+f[d[t]]-f[d[t]-(sm[t]-l)-1];
       // DEBUG(now);
        ans = std::max(ans,now);
    }
    printf("%lld\n",ans);
    return 0;
}