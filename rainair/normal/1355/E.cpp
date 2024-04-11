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

const int MAXN = 1e5 + 5;
int n,A,R,M;
LL a[MAXN],sm[MAXN];

inline LL calc(int x){
    int p = std::upper_bound(a+1,a+n+1,x)-a;
    if(p == n+1){
        return 1ll*A*(1ll*x*n-sm[n]);
    }
    LL up = 1ll*x*(p-1)-sm[p-1],down=sm[n]-sm[p-1]-1ll*(n-p+1)*x;
    LL ans = up*A+down*R;
    LL t = std::min(up,down);
    up -= t;down -= t;
    ans = std::min(ans,1ll*t*M+up*A+down*R);
    return ans;
}

int main(){
    scanf("%d%d%d%d",&n,&A,&R,&M);
    FOR(i,1,n) scanf("%lld",a+i);
    std::sort(a+1,a+n+1);
    FOR(i,1,n) sm[i] = sm[i-1]+a[i];
    int l = 0,r = 1e9;LL ans = 1e18;
    while(l <= r){
        int mid = (l + r) >> 1;
        LL t1 = calc(mid),t2 = calc(mid+1);
        ans = std::min(ans,std::min(t1,t2));
        if(t1 < t2) r = mid-1;
        else l = mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}