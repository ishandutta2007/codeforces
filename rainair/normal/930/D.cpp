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

const int MAXN = 2e5 + 233;
const int MAXM = 1e5 + 5;
int n;
std::vector<P> v[2];
std::vector<int> G[MAXN];
P pre[MAXN];

inline LL work(std::vector<P> &v){
	if(v.empty()) return 0;
	FOR(i,1,MAXN-1) G[i].clear();
	for(auto x:v) G[x.se].pb(x.fi);
	int l = 1e9,r = 0;pre[0] = MP(l,r);
	FOR(i,1,MAXN-1){
		for(auto x:G[i]) l = std::min(l,x),r = std::max(r,x);
		pre[i] = MP(l,r);
	}
	l = 1e9,r = 0;LL ans = 0;
	ROF(i,MAXN-1,1){
		for(auto x:G[i]) l = std::min(l,x),r = std::max(r,x);
		if(l >= r || pre[i-1].fi >= pre[i-1].se) continue;
		int ll = std::max(l,pre[i-1].fi),rr = std::min(r,pre[i-1].se);
		ans += std::max(0,rr-ll);
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		int x,y;scanf("%d%d",&x,&y);
		if((x+y)&1){
			v[1].pb(MP(MAXM+(x+y+1)/2,MAXM+(x-y-1)/2));// 
		}
		else{
			v[0].pb(MP(MAXM+(x+y)/2,MAXM+(x-y)/2));
		}
	}
	// for(auto &x:v[1]) x.fi -= 99998,x.se -= 99998;
	// for(auto x:v[1]) printf("%d %d\n",x.fi,x.se);
	printf("%lld\n",work(v[0])+work(v[1]));
	return 0;
}