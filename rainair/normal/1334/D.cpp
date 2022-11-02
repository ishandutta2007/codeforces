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
#define FOR(i,a,b) for(LL i = a;i <= b;++i)
#define ROF(i,a,b) for(LL i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;

inline void Solve(){
	int n;LL l,r;scanf("%d%lld%lld",&n,&l,&r);
	LL now = 0;
	int u=-1,v=-1;
	FOR(i,1,n){
		if(now+2ll*(n-i) < l){
			now += 2ll*(n-i);continue;
		}
		u = i;break;
	}
	if(u == -1){
		assert(l == r);
		printf("1\n");
		return;
	}
	LL t = l-now-1;
	v = u+1;v += t/2;
	now = u;if(t&1) now = v;
	FOR(i,l,r){
		printf("%lld ",now);
		if(now == u) now = v;
		else v++,now = u;
		if(v > n) u++,now = u,v = u+1;
		if(u == n) now = 1;
	}
	// exit(0);
	puts("");
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}