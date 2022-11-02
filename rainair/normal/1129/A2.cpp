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

const int MAXN = 5000+5;
std::vector<int> G[MAXN];
int n,m;

inline int calc(int x,int y){
	if(x == y) return 0;
	if(x < y) return y-x;
	return y+n-x;
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);
		if(u == v) continue;
		G[u].pb(v);
	}
	bool flag = 1;
	FOR(i,1,n) flag &= G[i].empty();
	if(flag){
		FOR(i,1,n) printf("0 ");puts("");return 0;
	}
	FOR(i,1,n) std::sort(all(G[i]));
	FOR(i,1,n){
		LL ans = 0;
		FOR(j,1,n){
			if(G[j].empty()) continue;
			int t = G[j].size();
			int p = std::lower_bound(all(G[j]),j)-G[j].begin();
			if(p == G[j].size()) p = 0;
			// if(i == 1 && j == 5){
				// DEBUG(calc(i,j));
				// DEBUG((t-1)*n);
				// DEBUG(claC(j))
			// }
			ans = std::max(ans,calc(i,j)+1ll*(t-1)*n+calc(j,G[j][p]));
		}
		printf("%lld ",ans);
		// DEBUG(ps);
		// exit(0);
	}
	puts("");
	return 0;
}