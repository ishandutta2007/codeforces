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

const int MAXN = 1e6 + 5;
bool p[MAXN];int prime[MAXN],cnt,tot;
LL n;int lim;
int id1[MAXN],id2[MAXN];
LL sm[MAXN],di[MAXN];

inline int getid(LL x){
    if(x <= lim) return id1[x];
    return id2[n/x];
}

inline void prework(int lim){
    FOR(i,2,lim){
        if(!p[i]) prime[++cnt] = i;
        for(int j = 1;j <= cnt && 1ll*i*prime[j] <= lim;++j){
            p[i*prime[j]] = 1;
            if(!(i%prime[j])) break;
        }
    }
}

int main(){
    scanf("%lld",&n);lim = std::sqrt(1.0*n)+1;
    prework(lim);
    for(LL l = 1,r;l <= n;l = r+1){
        LL x = n/l;r = n/x;
        if(x <= lim) id1[x] = ++tot;
        else id2[r] = ++tot;
        di[tot] = x;
    }
    FOR(i,1,tot) sm[i] = di[i]-1;
    FOR(i,1,cnt){
        int p = prime[i];
        FOR(j,1,tot){
            LL n = di[j];
            if(1ll*p*p > n) break;
            sm[j] -= sm[getid(n/p)]-(i-1);
        }
    }
    LL ans = 0;
//    FOR(i,1,tot) printf("%lld %lld\n",di[i],sm[i]);
    FOR(i,1,cnt){
        ans += std::max(0ll,sm[getid(n/prime[i])]-i);
    }
    FOR(i,1,cnt){
        if(1ll*prime[i]*prime[i]*prime[i] > n) break;
        ++ans;
    }
    printf("%lld\n",ans);
    return 0;
}