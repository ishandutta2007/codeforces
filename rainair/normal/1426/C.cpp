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
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		int q = std::sqrt(1.0*n);LL ans = 1e18;
		FOR(i,std::max(0,q-100),std::min(n,q+100)){
			ans = std::min(ans,i+(n+i)/(1+i) - 1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}