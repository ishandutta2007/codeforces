#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
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

const int MAXN = 6e5 + 5;
const int ha = 998244353;
int n,k;
P a[MAXN];
std::vector<int> S;
std::vector<int> l[MAXN],r[MAXN];

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int fac[MAXN],inv[MAXN];

inline void prework(){
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i]= 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
    if(n < 0 || m < 0 || n < m) return 0;
    return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int main(){
    prework();
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se),S.pb(a[i].fi),S.pb(a[i].se);
    std::sort(all(S));S.erase(std::unique(all(S)),S.end());
    FOR(i,1,n) a[i].fi = std::lower_bound(all(S),a[i].fi)-S.begin()+1,
        a[i].se = std::lower_bound(all(S),a[i].se)-S.begin()+1;
    FOR(i,1,n) l[a[i].fi].pb(i),r[a[i].se].pb(i);
    int now = 0,ans = 0;
    FOR(i,1,(int)S.size()){
        for(auto x:r[i-1]) now--;
        int t = 0;
        for(auto x:l[i]) ++t;
//        (ans += C(t,k)) %= ha;
        (ans += C(now+t,k)) %= ha;
        (ans += ha-C(now,k)) %= ha;
        now += t;
    }
    printf("%d\n",ans);
    return 0;
}