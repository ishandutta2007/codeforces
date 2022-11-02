#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
const int ha = 1e9 + 7;

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
int n,m,k;

inline int C(int n,int m){
    return (n < 0 || m < 0 || n < m) ? 0 : 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int a[MAXN];

inline void Solve(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%d",a+i);std::sort(a+1,a+n+1);
    int ans = 0,p = 1;
    FOR(i,1,n){
        while(a[i]-a[p] > k) ++p;
        (ans += C(i-p,m-1)) %= ha;
    }
    printf("%d\n",ans);
}

int main(){
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}