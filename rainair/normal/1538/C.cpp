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

const int MAXN = 2e5 + 5;

int a[MAXN],n,l,r;

inline LL calc(int L){// <= L
	LL ans = 0;
	FOR(i,1,n){
		int p = std::upper_bound(a+1,a+n+1,L-a[i])-a-1;
		if(p >= i) --ans;
		ans += p;
	}
	return ans;
}

inline void Solve(){
	scanf("%d%d%d",&n,&l,&r);
	FOR(i,1,n) scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	LL ans = calc(r)-calc(l-1);
	ans >>= 1;
	printf("%lld\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}