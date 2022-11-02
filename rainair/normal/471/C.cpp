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
#define int LL
signed main(){
	LL n;scanf("%lld",&n);
	int ans = 0;
	FOR(i,1,1000000){
		LL t = (3*i+1)*i/2;
		if(t > n) break;
		ans += ((n-t)%3==0);
	}
	printf("%d\n",ans);
	return 0;
}