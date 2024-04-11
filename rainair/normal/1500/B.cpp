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

inline char nc(){
    #define SIZE 1000000+3
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
    #undef SIZE
}

template <typename T>
inline void read(T &x){
    x = 0;int flag = 0;char ch = nc();
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}

const int MAXN = 1e6 + 5;

inline LL qmul(LL a,LL b,LL c){
    return a*b%c;
}

inline LL exgcd(LL a,LL b,LL &x,LL &y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    LL g = exgcd(b,a%b,x,y);
    LL t = x;x = y;y = t-(a/b)*y;
    return g;
}

LL x,y,nn,M,g;
LL aa[233],bb[233];

inline LL excrt(){
    LL ans = aa[1];M = bb[1];// M = lcm
    FOR(i,2,nn){
        LL a = M,b = bb[i],c = (aa[i]-ans%b+b)%b;//  ax=c(mod b)
        g = exgcd(a,b,x,y);
        LL bg = b/g;
        if(c%g) return 9e18;
        x = qmul(x,c/g,bg);
        ans = ans+M*x;
        M *= bg;
        ans = (ans+M)%M; // 
    }
    return (ans+M)%M;
}

int n,m,a[MAXN],b[MAXN];
LL k,mn[MAXN];
std::vector<int> G[MAXN];

inline bool chk(LL x){// 0..x
    LL ans = 0;
    FOR(i,1,2*std::max(n,m)){
        if(SZ(G[i]) <= 1) continue;
        if(mn[i] <= x) ans += 1+(x-mn[i])/M;
    }
    return x+1-ans < k;
}

int main(){
//    freopen("B.in","r",stdin);
    read(n);read(m);read(k);
    FOR(i,0,n-1) read(a[i]);
    FOR(i,0,m-1) read(b[i]);
    FOR(i,0,n-1) G[a[i]].pb(i);
    FOR(i,0,m-1) G[b[i]].pb(i);
    nn = 2;
    FOR(i,1,2*std::max(n,m)){
        if(SZ(G[i]) <= 1) continue;
        aa[1] = G[i][0];bb[1] = n;
        aa[2] = G[i][1];bb[2] = m;
        // mn+kM
        mn[i] = excrt();
    }
    M = 1ll*n*m/std::__gcd(n,m);
    LL l = 0,r = 1e18,ans = -1;
    while(l <= r){
        LL mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,l = mid+1;
        else r = mid-1;
    }
    printf("%lld\n",ans+2);
    return 0;
}