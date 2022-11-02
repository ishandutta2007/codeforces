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

const int MAXN = 2e5 +5;
int n,p[MAXN],c[MAXN];
std::vector<int> G[MAXN];
bool vis[MAXN];
int col[MAXN];

inline bool chk(int c,int x){
	FOR(i,0,x) col[i] = -1;
	FOR(i,0,(int)G[c].size()-1){
		if(col[i%x] == -1){
			col[i%x] = ::c[G[c][i]];
		}
		else if(col[i%x] != ::c[G[c][i]]){
			col[i%x] = -2;
		}
	}
	FOR(i,0,x-1) if(col[i] != -2) return 1;
	return 0;
}

inline int work(int c){
	int n = G[c].size(),res = n;
	int q = std::sqrt(1.0*n);
	std::vector<int> dec;
	FOR(i,1,q){
		if(!(n%i)){
			dec.pb(i);
			if(i != n/i) dec.pb(n/i);
		}
	}
	std::sort(all(dec));
	for(auto x:dec) if(chk(c,x)){res=x;break;}
	return res;
}

inline void Solve(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",p+i),G[i].clear();
	FOR(i,1,n) scanf("%d",c+i),vis[i] = 0;int m = 0;
	FOR(i,1,n){
		if(vis[i]) continue;
		int x = p[i];++m;G[m].pb(i);vis[i] = 1;
		while(x != i){
			G[m].pb(x);x = p[x];vis[x] = 1;
		}
	}
	int ans = 1e9;
	FOR(i,1,m) ans = std::min(ans,work(i));
	printf("%d\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}