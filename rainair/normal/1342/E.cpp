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

const int MAXN = 2e5 + 5;
const int ha = 998244353;

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
	fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
	inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
	if(n < m) return 0;
	return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

inline int S2(int n,int m){
	int res = 0;
	FOR(i,0,m){
		int gx = 1ll*C(m,i)*qpow(m-i,n)%ha;
		if(i&1) gx = ha-gx;
		(res += gx) %= ha;
	}
	res = 1ll*res*inv[m]%ha;
	return res;
}

int main(){
	int n;LL k;scanf("%d%lld",&n,&k);
	if(k >= n) {puts("0");exit(0);}
	prework();
	printf("%lld\n",(k==0?1ll:2ll)*fac[n-k]%ha*C(n,n-k)%ha*S2(n,n-k)%ha);
	return 0;
}
/*
,a[i]i
\sum_{i=1}^n (a[i]-1) = k
\sum_{i=1}^n[a[i] >= 1] = n-k
C(n,n-k)S2(n,n-k)
*/