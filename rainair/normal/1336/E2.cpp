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

const int MAXN = 53+5;
const int ha = 998244353;
const int inv2 = 499122177;
int n,m;
LL b[MAXN];

inline void insert(LL x){
	ROF(i,m-1,0){
		if((x>>i)&1){
			if(b[i]) x ^= b[i];
			else{b[i] = x;break;}
		}
	}
}

int sz;

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

namespace Subtask1{
	std::vector<LL> v;
	int ans[233]; 
	
	inline void dfs(int step,LL now){
		if(step == sz){
			add(ans[__builtin_popcountll(now)],1);
			return;
		}
		dfs(step+1,now);
		dfs(step+1,now^v[step]);
	}
	
	inline void Solve(){
		FOR(i,0,m-1) if(b[i]) v.pb(b[i]);
		dfs(0,0);
		int pw = 1;FOR(i,1,n-sz) pw = 2ll*pw%ha;
		FOR(i,0,m) printf("%lld ",1ll*ans[i]*pw%ha);puts("");
		exit(0);
	}
}

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
	if(n < 0 || m < 0) return 0;
	return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

namespace Subtask2{
	LL B[MAXN];
	int f[666],ans[233];
	std::vector<LL> v;
	
	inline void dfs(int step,LL now){
		if(step == m-sz){
			f[__builtin_popcountll(now)]++;
			return;
		}
		dfs(step+1,now);dfs(step+1,now^v[step]);
	}
	
	inline void Solve(){
		FOR(i,0,m-1){
			FOR(j,0,m-1){
				B[j] |= ((b[i]>>j)&1)<<i;
			}
		}
		FOR(i,0,m-1){
			B[i] ^= (1ll<<i);
			if((B[i]>>i)&1) v.pb(B[i]);
		}
		dfs(0,0);
		FOR(c,0,m){
			FOR(d,0,m){
				int sm = 0;
				FOR(i,0,d){
					int gx = 1ll*C(d,i)*C(m-d,c-i)%ha;
					if(i&1) gx = ha-gx;
					add(sm,gx);
				}
				sm = 1ll*sm*f[d]%ha;
				add(ans[c],sm);
			}
			ans[c] = 1ll*ans[c]*qpow(inv2,m-sz)%ha;
			ans[c] = 1ll*ans[c]*qpow(2,n-sz)%ha;
			printf("%d ",ans[c]);
		}
		puts("");exit(0);
	}
}

int main(){
	prework();
	scanf("%d%d",&n,&m);
	FOR(i,1,n){
		LL x;scanf("%lld",&x);insert(x);
	}
	ROF(i,m-1,0){
		if(b[i]){
			FOR(j,i+1,m-1){
				if((b[j]>>i)&1) b[j] ^= b[i];
			} 
		}
	}
	FOR(i,0,m-1) if(b[i]) ++sz;
	if(sz <= 26) Subtask1::Solve();
	else Subtask2::Solve();
	return 0;
}