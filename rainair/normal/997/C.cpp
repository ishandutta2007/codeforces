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
const int MAXN = 1e6 + 5;

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
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int main(){
	prework();
	int n;scanf("%d",&n);
	/*int ans = 0;
	FOR(i,0,n){
		FOR(j,0,n){
			if(i == 0 && j == 0) continue;
			if(!(i == 0 || j == 0)) continue;
			int gx = 1ll*C(n,i)*C(n,j)%ha*qpow(3,n*n-n*i-n*j+i*j)%ha;
			if(i == 0) gx = 1ll*gx*qpow(3,j)%ha;
			else if(j == 0) gx = 1ll*gx*qpow(3,i)%ha;
			else gx = 3ll*gx%ha;
			if((i+j)&1) gx = ha-gx;
			(ans += gx) %= ha;
		}
	}
	DEBUG(ans);*/
	// 231494880
	int ans = 0;
	FOR(i,1,n){
		int gx = 1ll*C(n,i)*qpow(3,i)%ha*qpow(3,1ll*n*(n-i)%(ha-1))%ha;
		if(i&1) gx = ha-gx;
		(ans += gx) %= ha;
	}
	ans = 2ll*ans%ha;
	// DEBUG(ans);
	FOR(i,1,n){
		// int sm = 0;
		// FOR(j,1,n){
			// int gg = 1ll*C(n,j)*qpow(3,(n-i)*(n-j))%ha;
			// gg = 3ll*gg%ha;
			// if(j&1) gg = ha-gg;
			// (sm += gg) %= ha;
		// }
		// DEBUG(sm);
		int tt = (qpow(3,n-i)+ha-1)%ha;
		tt = qpow(tt,n);
		(tt += ha-qpow(3,1ll*(n-i)*n%(ha-1)))%=ha;
		tt = 3ll*tt%ha;
		int gx = 1ll*C(n,i)*tt%ha;
		if(i&1) gx = ha-gx;
		(ans += gx) %= ha;
	}
	ans = ha-ans;
	printf("%d\n",ans);
	return 0;
}
/*
:? 
*/