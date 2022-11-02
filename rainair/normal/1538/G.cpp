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

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int a,b,lim1,lim2;
		scanf("%d%d%d%d",&lim1,&lim2,&a,&b);
		int ans = std::min(lim1/b,lim2/a);
		ans = std::max(ans,std::min(lim1/a,lim2/b));
		if(a != b){
			LL xx = 1ll*(1ll*a*lim1-1ll*b*lim2)/(1ll*a*a-1ll*b*b);
			xx = std::max(xx,0ll);
			xx = std::min(xx,(LL)std::min(lim1/a,lim2/b));
			FOR(x,std::max(0ll,xx-500),xx+500){
				if(1ll*a*x <= lim1 && 1ll*b*x <= lim2){
					ans = std::max(ans,(int)x+(int)std::min((lim1-a*x)/b,(lim2-b*x)/a));
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}