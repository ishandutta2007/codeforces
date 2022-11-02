
// Problem: E. Calendar Ambiguity
// Contest: Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1389/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

int main(){
	int T;scanf("%d",&T);
	while(T--){
		LL m,d,w;scanf("%lld%lld%lld",&m,&d,&w);
		LL g = std::__gcd(d-1,w);w /= g;
		LL lim = std::min(m,d);
		LL res = lim*(lim/w) - w*(lim/w)*(lim/w+1)/2;
		printf("%lld\n",res);
	}
	return 0;
}