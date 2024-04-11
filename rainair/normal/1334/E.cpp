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

LL D;
std::vector<LL> dec;
const int MAXN = 1e5 + 5;
const int ha = 998244353;
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
	inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
	if(n < m) return 0;
	return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int main(){
	prework();
	scanf("%lld",&D);
	int q = std::sqrt(1.0*D);
	FOR(i,2,q){
		if(!(D%i)){
			while(!(D%i)) D /= i;
			dec.pb(i);
		}
	}
	if(D > 1) dec.pb(D);
	scanf("%d",&q);
	while(q--){
		LL u,v;scanf("%lld%lld",&u,&v);
		std::vector<int> G1,G2;
		for(auto x:dec){
			int e1=0,e2=0;
			while(!(u%x)) u /= x,e1++;
			while(!(v%x)) v /= x,e2++;
			if(e1 == e2) continue;
			if(e1 < e2) G1.pb(e2-e1);
			else G2.pb(e1-e2);
		}
		int sm1=0,sm2=0;
		for(auto x:G1) sm1 += x;
		for(auto x:G2) sm2 += x;
		int ans = 1;
		for(auto x:G1) ans = 1ll*ans*C(sm1,x)%ha,sm1 -= x;
		for(auto x:G2) ans = 1ll*ans*C(sm2,x)%ha,sm2 -= x;
		printf("%d\n",ans);
	}
	return 0;
}