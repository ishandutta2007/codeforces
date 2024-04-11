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

const int ha = 998244353;
const int MAXN = 2e5 + 5;
int fac[MAXN],inv[MAXN];

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

inline void prework(){
	fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
	inv[MAXN-1] = qpow(fac[MAXN-1]);
	ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int main(){
	prework();
	int n,m;scanf("%d%d",&n,&m);
	int ans = 0;
	// FOR(i,2,n-1) FOR(j,1,m){
		// int gx = 1ll*C(j-1,n-2)*C(n-3,i-2)%ha*(n-2)%ha;
		// (ans += gx) %= ha;
	// }
	// int sm = 0;
	// FOR(j,1,m){// =C(m,n-1)
		// int gx = 1ll*C(j-1,n-2);
		// (sm += gx) %= ha;
	// }
	// sm = C(m,n-1);
	// FOR(i,2,n-1){
		// (ans += 1ll*C(n-3,i-2)%ha) %= ha;
	// }
	if(n < 3){
		puts("0");
		return 0;
	}
	ans = 1ll*(n-2)%ha*C(m,n-1)%ha*qpow(2,n-3)%ha;
	printf("%d\n",ans);
	return 0;
}