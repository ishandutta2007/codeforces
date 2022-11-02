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
int n;LL x[MAXN],d[MAXN],l[MAXN],r[MAXN];
int st[MAXN],tp;

inline void get(LL r[]){
    st[tp = 1] = 0;
    FOR(i,1,n){
        while(tp >= 2 && std::abs(x[st[tp-1]]-x[i]) > d[st[tp]]*2) --tp;
        r[i] = std::max(0ll,2*d[i]-std::abs(x[st[tp]]-x[i]));
        st[++tp] = i;
    }
}
//std::mt19937 g(114514);
int main(){
//    n = 1e5;
    scanf("%d",&n);
    FOR(i,0,n+1) scanf("%lld",x+i);
//    x[0] = 0;FOR(i,1,n+1) x[i] = 1+g()%1000000000;
//    std::sort(x,x+n+2);
//    FOR(i,1,n) d[i] = 1+g()%100000;
    FOR(i,1,n) scanf("%lld",d+i);
    get(r);std::reverse(x,x+n+2);std::reverse(d+1,d+n+1);
    get(l);std::reverse(x,x+n+2);std::reverse(d+1,d+n+1);std::reverse(l+1,l+n+1);
    FOR(i,1,n){
        if(x[i]+r[i] >= x[n+1] || x[i]-l[i] <= 0){
            puts("0");
            return 0;
        }
    }
    tp = 0;r[0] = 1e18;l[n+1] = 1e18;
    LL res = 1e18;
    FOR(i,0,n){
        if(r[i]){
            while(tp && x[st[tp]]+r[st[tp]] <= x[i]+r[i]) --tp;
            st[++tp] = i;
        }
        if(l[i+1]){
            int l = 1,r = tp,ans = -1;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(::r[st[mid]]+x[st[mid]] >= x[i+1]-::l[i+1]) ans = mid,l = mid+1;
                else r = mid-1;
            }
            res = std::min(res,x[i+1]-x[st[ans]]);
        }
    }
    printf("%.10f\n",res/2.0);
    return 0;
}