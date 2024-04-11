#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 5000+5;
const int MAXM = 3e5+2;

inline int gcd(int a,int b){
    return !b ? a : gcd(b,a%b);
}
int n,a[MAXN],pre[MAXN],b[MAXN],m;
int cf[MAXN],c[MAXN];
std::unordered_map<int,int> S,FF;
bool vis[MAXM+233];
int prime[MAXM+233],cnt;

inline void prework(){
    FOR(i,2,MAXM){
        if(!vis[i]) prime[++cnt] = i;
        for(int j = 1;j <= cnt && i*prime[j] <= MAXM;++j){
            vis[i*prime[j]] = true;
            if(!(i%prime[j])) break;
        }
    }
}


inline bool pd(LL x){
    int q = std::sqrt(x);
    FOR(i,2,q){
        if(!(x%i)) return true;
    }
    return false;
}
std::vector<int> res;
inline void fj(LL x){
    if(!pd(x)){
        res.pb(x);return;
    }
    int q = std::sqrt(1.0*x);
    for(int i = 1;i <= cnt && prime[i] <= q;++i){
        int p = prime[i];
        while(!(x%p)) res.pb(p),x /= p;
    }
    if(x > 1) res.pb(x);
}

inline LL calcf(LL val){
    if(val == 1) return 0;
    if(FF[val]) return FF[val];
    res.clear();fj(val);int ans = 0;
    for(auto x:res){
        if(S[x]) ans--;
        else ans++;
    }
    FF[val] = ans;
    return ans;
}

signed main(){
  //  DEBUG(MAXM);
    prework();
    scanf("%lld%lld",&n,&m);pre[0] = 0;
    FOR(i,1,n){
        scanf("%lld",a+i),pre[i] = gcd(pre[i-1],a[i]),cf[i] = 1;
    }
    FOR(i,1,m){
        scanf("%lld",b+i),S[b[i]] = 1;
    }
   // FOR(i,1,n) printf("%d ",calcf(a[i]));
    int k = 1;
    ROF(i,n,1){
        int g = pre[i]/k;//DEBUG(g);
        int h = calcf(g);//DEBUG(h);
        if(h < 0){
            k *= g;
            cf[i] *= g;
        }
    }
    ROF(i,n-1,1) cf[i] *= cf[i+1];
    ROF(i,n,1){
        c[i] = a[i]/cf[i];
       // DEBUG(a[i]);
    }
    LL ans = 0;
    FOR(i,1,n) ans += calcf(c[i]);
    printf("%lld\n",ans);
    return 0;
}