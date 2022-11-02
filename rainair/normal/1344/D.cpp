#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<LL,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
int n,a[MAXN],b[MAXN];
LL k;

inline LL f(LL x){
    return -3*x*x-3*x-1;
}

inline int calc(int i,LL lim){
    if(f(0)+a[i] < lim) return 0;
    int l = 0,r = a[i]-1,ans = -2;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(f(mid)+a[i] >= lim) ans = mid,l = mid+1;
        else r = mid-1;
    }
    return ans+1;
}

inline bool chk(LL mid){
    FOR(i,1,n) b[i] = calc(i,mid);
    FOR(i,1,n) if(b[i] == -1) return 0;
    LL sm = 0;
    FOR(i,1,n) sm += b[i];
    return sm <= k;
}

std::mt19937 g(time(NULL));

int main(){
    scanf("%d%lld",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    LL l = -4e18,r = 1e9,ans = 0;
    while(l <= r){
        LL mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    chk(ans);
    LL t = k;FOR(i,1,n) t -= b[i];
    std::priority_queue<P> q;
    FOR(i,1,n) if(b[i]+1 <= a[i]) q.push(MP(f(b[i]+1)+a[i],i));
    while(t--){
        if(q.empty()) break;
        P v = q.top();q.pop();
        b[v.se]++;
        if(b[v.se]+1 <= a[v.se]) q.push(MP(f(b[v.se]+1)+a[v.se],v.se));
    }
    FOR(i,1,n) printf("%d ",b[i]);puts("");
//    LL res = 0;
//    FOR(i,1,n) res += b[i]*(a[i]-b[i]*b[i]);
//    DEBUG(res);
    return 0;
}