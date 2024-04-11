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

const int MAXN = 3e5 + 5;
const int ha = 998244353;

int n,m;
int l[MAXN],r[MAXN],a[MAXN],b[MAXN];
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
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int sm[41][MAXN];

int main(){
	prework();
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d%d",l+i,r+i),sm[0][l[i]]++,sm[0][r[i]+1]--;
	FOR(i,1,m) scanf("%d%d",a+i,b+i);
	FOR(i,1,n) sm[0][i] += sm[0][i-1];
	FOR(c,1,40){
		FOR(i,1,n){
			sm[c][i] = (sm[c][i-1]+C(sm[0][i]-c,i-c))%ha;
		}
	}
	FOR(i,1,n) sm[0][i] = (sm[0][i-1]+C(sm[0][i],i))%ha;
	int ans = 0;
	FOR(S,0,(1<<m)-1){
		int l = 1,r = n;std::vector<int> _;
		FOR(i,0,m-1){
			if(!((S>>i)&1)) continue;
			l = std::max({l,::l[a[i+1]],::l[b[i+1]]});
			r = std::min({r,::r[a[i+1]],::r[b[i+1]]});
			_.pb(a[i+1]);_.pb(b[i+1]);
		}
		if(l > r) continue;
		std::sort(all(_));_.erase(std::unique(all(_)),_.end());
		int gx = (sm[_.size()][r]+ha-sm[_.size()][l-1])%ha;
		if(__builtin_popcount(S)&1) gx = ha-gx;
		(ans += gx) %= ha;
	}
	printf("%d\n",ans);
	return 0;
}