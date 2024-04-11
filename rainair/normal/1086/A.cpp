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

const int MAXN = 1000;
P a[MAXN];

int main(){
	FOR(i,1,3) scanf("%d%d",&a[i].fi,&a[i].se);
	std::sort(a+1,a+3+1);
	int mx = a[1].se,mn = a[1].se,sm = a[1].se;
	FOR(i,2,3) mx = std::max(mx,a[i].se),mn = std::min(mn,a[i].se),sm += a[i].se;
	int y = sm-mx-mn;
	std::vector<P> ans;
	FOR(i,a[1].fi,a[3].fi) ans.pb(MP(i,y));
	FOR(i,1,3){
		if(a[i].se == y) continue;
		if(a[i].se > y){
			FOR(j,y+1,a[i].se) ans.pb(MP(a[i].fi,j));
		}
		else{
			FOR(j,a[i].se,y-1) ans.pb(MP(a[i].fi,j));
		}
	}
	std::sort(all(ans));ans.erase(std::unique(all(ans)),ans.end());
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d %d\n",x.fi,x.se);
	return 0;
}