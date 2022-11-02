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

const int MAXN = 2000 + 5;
const int ha = 1e9 + 7;
int n,m;
char str[MAXN][MAXN];

int a[MAXN][MAXN];

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

inline void Solve(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%s",str[i]+1);
	int c0 = 0,c1 = 0;
	FOR(i,1,n) FOR(j,1,m) c0 += (str[i][j]=='0');
	c1 = n*m-c0;
	if(!c0){
		printf("%d\n",(qpow(2,c1)-1+ha)%ha);
		return;
	}
	printf("%d\n",qpow(2,c1));
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}