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
const int BASE = 31;
const int ha = 1e9 + 7;

U LL sm[MAXN],pw[MAXN];
char str[MAXN];int n,m;

inline U LL calc(int l,int r){
	return sm[r]-sm[l-1]*pw[r-l+1];
}

int f[MAXN],g[MAXN],h[MAXN];
char S[MAXN],T[MAXN];
unsigned LL hsh;
// f[i]: i

int main(){
	pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = BASE*pw[i-1];
	scanf("%s",S+1);n = strlen(S+1);
	scanf("%s",T+1);m = strlen(T+1);
	FOR(i,1,m) hsh = hsh*BASE+T[i]-'a'+1;
	FOR(i,1,n) sm[i] = sm[i-1]*BASE+S[i]-'a'+1;
	int p = -1;
	FOR(i,m,n){
		if(calc(i-m+1,i) == hsh) p = i-m+1;
		if(p > 0) f[i] = p;
		if(p-1 >= 0) (f[i] += h[p-1]) %= ha;
		// FOR(j,0,p-1){
			// FOR(k,0,j)
				// (f[i] += f[k]) %= ha;
		// }
		g[i] = (g[i-1]+f[i])%ha;
		h[i] = (h[i-1]+g[i])%ha;
	}
	int ans = 0;FOR(i,1,n) (ans += f[i]) %= ha;
	printf("%d\n",ans);
	return 0;
}