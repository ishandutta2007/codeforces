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

const int MAXN = 1e5 + 5;
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

inline void prework(){
	fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
	inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int n,k;
char str[MAXN];
int a[MAXN];
int sm[MAXN];
int pw[MAXN],ipw[MAXN];

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

int main(){
	prework();
	pw[0] = ipw[0] = 1;pw[1] = 10;ipw[1] = qpow(10);
	FOR(i,2,MAXN-1) pw[i] = 1ll*pw[i-1]*pw[1]%ha,ipw[i] = 1ll*ipw[i-1]*ipw[1]%ha;
	scanf("%d%d",&n,&k);scanf("%s",str+1);
	FOR(i,1,n) a[i] = str[i]-'0';
	FOR(i,0,n) sm[i] = 1ll*C(n-i-2,k-1)*pw[i]%ha;
	FOR(i,1,n) add(sm[i],sm[i-1]);int ans = 0;
	FOR(i,1,n){
		if(n-1-i < 0) continue;
		int gx = sm[n-1-i];
		gx = 1ll*gx*a[i]%ha;
		// gx = 1ll*gx*ipw[i]%ha;
		add(ans,gx);
	}
	FOR(i,1,n){
		int gx = 1ll*a[i]*pw[n-i]%ha*C(i-1,k)%ha;
		add(ans,gx);
	}
	printf("%d\n",ans);
	// int t = 0;
	// FOR(i,1,n){
		// FOR(j,i,n-1){
			// add(t,1ll*a[i]*pw[j-i]%ha*C(n-j+i-2,k-1)%ha);
		// }
		// add(t,1ll*a[i]*pw[n-i]%ha*C(i-1,k)%ha);
	// }
	// DEBUG(t);
	return 0;
}