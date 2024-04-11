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

const int ha = 1e9 + 7;
const int MAXN = 200 + 5;
int n,k;LL m;

inline int qpow(int a,LL n=ha-2){
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

LL cnt[MAXN];
int f[2][MAXN*MAXN],now;

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

int t[MAXN][MAXN];

int main(){prework();
	scanf("%d%lld%d",&n,&m,&k);
	FOR(i,1,n) cnt[i] = m/n;
	m %= n;
	FOR(i,1,m) cnt[i]++;
	FOR(i,1,n){
		FOR(j,0,n){
			t[i][j] = qpow(C(n,j),cnt[i]);
		}
	}
	f[now=0][0] = 1;
	FOR(i,1,n){
		CLR(f[now^1],0);
		FOR(j,0,n*(i-1)){
			if(!f[now][j]) continue;
			FOR(k,0,n){
				add(f[now^1][j+k],1ll*f[now][j]*t[i][k]%ha);
			}
		}
		now ^= 1;
	}
	printf("%d\n",f[now][k]);
	return 0;
}