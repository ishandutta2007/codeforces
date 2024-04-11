#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5000 + 5;
const int ha = 998244353;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n&1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int S[MAXN][MAXN];
int n,m,k;

int main(){
	S[0][0] = 1;
	FOR(i,1,MAXN-1) FOR(j,1,i) S[i][j] = (S[i-1][j-1] + 1ll*j*S[i-1][j])%ha;
	scanf("%d%d%d",&n,&m,&k);
	int ans = 0,p = qpow(m),nown = 1,nowp = 1;
	FOR(i,0,k){
		(ans += 1ll*S[k][i]*nowp%ha*nown%ha) %= ha;
		nown = 1ll*nown*(n-i)%ha;
		nowp = 1ll*nowp*p%ha;
	}
	printf("%d\n",ans);
	return 0;
}