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
const int MAXN = 5000+5;
int n,m,k;
bool row[MAXN],col[MAXN];
int gr[MAXN][MAXN],gc[MAXN][MAXN];

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
int tr,tc;

inline void prework(){
	fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
	inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

inline int work(int n,int m){
	int ans = 0;
	FOR(a,0,std::min(n,m/2)){
		FOR(b,0,std::min(m,n/2)){
			add(ans,1ll*gc[m][a]*gr[n][b]%ha*C(n-2*b-tr,a)%ha*C(m-2*a-tc,b)%ha*fac[a]%ha*fac[b]%ha);
		}
	}
	return ans;
}

int main(){
	prework();
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,k){
		int r1,c1,r2,c2;scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		row[r1] = row[r2] = col[c1] = col[c2] = 1;
	}
	FOR(i,1,n) tr += row[i];
	FOR(i,1,m) tc += col[i];
	gr[0][0] = 1;
	FOR(i,1,n){
		FOR(j,0,i/2){
			gr[i][j] = gr[i-1][j];
			if(i-2 >= 0 && !row[i] && !row[i-1]) add(gr[i][j],gr[i-2][j-1]);
		}
	}
	gc[0][0] = 1;
	FOR(i,1,m){
		FOR(j,0,i/2){
			gc[i][j] = gc[i-1][j];
			if(i-2 >= 0 && !col[i] && !col[i-1]) add(gc[i][j],gc[i-2][j-1]);
		}
	}
	printf("%d\n",work(n,m));
	return 0;
}