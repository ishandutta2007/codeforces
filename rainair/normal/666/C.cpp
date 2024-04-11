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

int fac[MAXN],inv[MAXN];
char str[MAXN];

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

int m;
int id[MAXN];
int tot = 0;
int ans[450][MAXN];
int pw[MAXN];
int im;

int main(){
	prework();pw[0] = 1;pw[1] = 1ll*25*qpow(26)%ha;
	FOR(i,2,MAXN-1) pw[i] = 1ll*pw[i-1]*pw[1]%ha;
	int T;scanf("%d",&T);
	scanf("%s",str+1);m = strlen(str+1);
	id[m] = ++tot;
	FOR(i,m,100000){
		ans[tot][i] = (ans[tot][i-1]+1ll*C(i-1,m-1)*pw[i]%ha) % ha;
	}
	im = qpow(25,m);im = qpow(im);
	while(T--){
		int opt;scanf("%d",&opt);
		if(opt == 1){
			scanf("%s",str+1);m = strlen(str+1);
			im = qpow(25,m);im = qpow(im);
			if(id[m]) continue;
			id[m] = ++tot;
			FOR(i,m,100000){
				ans[tot][i] = (ans[tot][i-1]+1ll*C(i-1,m-1)*pw[i]%ha) % ha;
			}
		}
		else{
			int n;scanf("%d",&n);
			printf("%lld\n",1ll*ans[id[m]][n]*qpow(26,n)%ha*im%ha);
		}
	}
	return 0;
}
/*
f[i][j] i,j
f[0][0] = 1;
j!=m:
25f[i][j] -> f[i+1][j] (1)
f[i][j] -> f[i+1][j+1] (2)
else:
26f[i][m] -> f[i+1][m] (3)

f[n][m]
(2)  m ,1
n-m (2)1,26 

msqrt 
*/