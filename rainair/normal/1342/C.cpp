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
#define int LL
int a,b,g;

inline LL calc(LL n){
	if(n <= b-1) return n;
	LL a1 = a/g;
	LL t = (n-b+1)/(a1*b);
	return b-1+t*b+std::max(0ll,n-1ll*b*a1*(t+1)+1);
}

signed main(){
	// DEBUG(calc(10));
	// exit(0);
	int T;scanf("%lld",&T);
	while(T--){
		int q;scanf("%lld%lld%lld",&a,&b,&q);g = std::__gcd(a,b);
		if(a > b) std::swap(a,b);
		while(q--){
			LL l,r;scanf("%lld%lld",&l,&r);
			LL res = calc(r)-calc(l-1);
			printf("%lld ",r-l+1-res);
		}
		puts("");
	}
	return 0;
}