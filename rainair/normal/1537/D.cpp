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

const int MAXN = 1e5 + 5;

bool p[MAXN];int prime[MAXN],cnt;

inline void prework(){
	FOR(i,2,MAXN-1){
		if(!p[i]) prime[++cnt] = i;
		for(int j = 1;j <= cnt && 1ll*i*prime[j] < MAXN;++j){
			p[i*prime[j]] = 1;
			if(!(i%prime[j])) break;
		}
	}
}

std::vector<int> dec[MAXN];

int f[MAXN];
// 1: win

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		if(n&1){
			puts("Bob");
			continue;
		}
		if(__builtin_popcount(n) == 1 && __builtin_ctz(n)&1){
			puts("Bob");
			continue;
		}
		puts("Alice");
		continue;
	}
	exit(0);
	FOR(i,1,MAXN-1) for(int j = i;j < MAXN;j += i) dec[j].pb(i);
	f[0] = 0;f[1] = 0;
	FOR(i,2,MAXN-1){
		for(auto x:dec[i]) if(x != 1 && x != i) f[i] |= !f[i-x];
	}
	FOR(i,1,MAXN-1){
		if(i&1) assert(!f[i]);
		else{
			if(__builtin_popcount(i) == 1 && __builtin_ctz(i)&1) assert(!f[i]);
			else assert(f[i]);
		}
		printf("%d %d\n",i,f[i]);
	}
	exit(0);
	return 0;
}