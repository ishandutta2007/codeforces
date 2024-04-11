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

const int MAXN = 2e5 + 5;

std::vector<int> G[MAXN];
int n,m;
LL a[MAXN],b[MAXN];
int col[MAXN];
bool flag;

inline void dfs(int v,int fa=0){
	for(auto x:G[v]){
		if(x == fa) continue;
		if(!col[x]){
			col[x] = 3-col[v];
			dfs(x,v);
			a[v] -= a[x];
			a[x] = 0;
			b[v] -= b[x];
			b[x] = 0;
		}
		else flag &= (col[x]!=col[v]);
	}
}

inline void Solve(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) G[i].clear(),col[i] = 0;flag = 1;
	FOR(i,1,n) scanf("%lld",a+i);
	FOR(i,1,n) scanf("%lld",b+i);
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);
		G[u].pb(v);G[v].pb(u);
	}
	col[1] = 1;dfs(1);
	if(!flag){
		puts(!((a[1]-b[1])&1) ? "YES" : "NO");
	}
	else{
		puts(a[1]==b[1] ? "YES" : "NO");
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}