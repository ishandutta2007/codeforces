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
const int MAXN = 2e5 + 5;
int a[MAXN],b[MAXN];

signed main(){
	int k,n,m,ta,tb;scanf("%lld%lld%lld%lld%lld",&n,&m,&ta,&tb,&k);
	if(k >= n || k >= m){
		puts("-1");
		return 0;
	}
	FOR(i,1,n) scanf("%lld",a+i);
	FOR(i,1,m) scanf("%lld",b+i);
	int tp = 1;
	LL ans = 0;
	FOR(i,1,std::min(n,k+1)){
		int t = k-i+1;
		while(tp <= m && b[tp] < a[i]+ta) tp++;
		if(tp+t > m){
			puts("-1");return 0;
		}
		ans = std::max(ans,b[tp+t]+tb);
	}
	if(ans == 1e18) ans = -1;
	printf("%lld\n",ans);
	return 0;
}