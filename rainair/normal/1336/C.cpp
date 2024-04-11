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

const int MAXN = 3000+5;
const int ha = 998244353;

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

char S[MAXN],T[MAXN];
int n,m;
int f[MAXN][MAXN];

inline bool equal(int x,int y){
	return (x >= 1 && x <= n && y >= 1 && y <= n) && ((y > m) || (S[x] == T[y]));
}

int main(){
	scanf("%s%s",S+1,T+1);
	n = strlen(S+1);m = strlen(T+1);
	FOR(i,1,n) f[i][i] = 2*equal(1,i);
	FOR(len,1,n-1){
		FOR(l,1,n-len+1){
			int r = l+len-1;
			if(!f[l][r]) continue;
			if(equal(len+1,l-1)) add(f[l-1][r],f[l][r]);
			if(equal(len+1,r+1)) add(f[l][r+1],f[l][r]);
		}
	}
	int ans = 0;
	FOR(i,m,n) add(ans,f[1][i]);
	printf("%d\n",ans);
	return 0;
}