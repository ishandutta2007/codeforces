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

const int MAXN = 3e5 + 5;
int n,q,k;
LL sm[MAXN];
int a[MAXN];

int main(){
    scanf("%d%d%d",&n,&q,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,2,n-1) sm[i] = sm[i-1]+a[i+1]-a[i-1]-2;
    sm[n] = sm[n-1];
    while(q--){
        int l,r;scanf("%d%d",&l,&r);
        if(l == r){
            printf("%d\n",k-1);
            continue;
        }
        LL ans = 0;
        if(l+1 <= r-1) ans = sm[r-1]-sm[l];
        ans += std::max(0,k-a[r])+std::max(0,a[r]-a[r-1]-1);
        ans += std::max(0,a[l]-1)+std::max(0,a[l+1]-a[l]-1);
        printf("%lld\n",ans);
    }
    return 0;
}