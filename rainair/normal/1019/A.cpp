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

const int MAXN = 3000+5;
int n,m;
std::vector<int> G[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n){
		int p,c;scanf("%d%d",&p,&c);G[p].pb(c);
	}
	FOR(i,1,m) std::sort(all(G[i]));
	LL res = 1e18;
	FOR(x,1,n){
		LL ans = 0;int cnt = G[1].size();
		std::vector<int> S;
		FOR(i,2,m){
			if(G[i].size() >= x){
				int k = (int)G[i].size()-x;
				FOR(j,0,k) ans += G[i][j],++cnt;
				FOR(j,k+1,(int)G[i].size()-1) S.pb(G[i][j]);
			}
			else{
				for(auto x:G[i]) S.pb(x);
			}
		}
		std::sort(all(S));
		if(cnt < x){
			int t = x-cnt;
			FOR(i,0,t-1) ans += S[i];
		}
		res = std::min(res,ans);
	}
	printf("%lld\n",res);
	return 0;
}