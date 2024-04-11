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
	LL a,b;scanf("%lld%lld",&a,&b);LL n = a+b;
	LL ans = 0;
	for(LL l = 1,r;l <= n;l = r+1){
		r = n/(n/l);
		LL g = n/l;
		LL la = (a+g)/(g+1),ra = a/g;
		LL lb = (b+g)/(g+1),rb = b/g;
		if(la > ra) continue;
		if(lb > rb) continue;
		LL ll = std::max(l,la+lb),rr = std::min(r,ra+rb);
		// if(l == 2){
			// DEBUG(ll);DEBUG(rr);
		// }
		if(ll > rr) continue;
		ans += rr-ll+1;
	}
	printf("%lld\n",ans);
	return 0;
}