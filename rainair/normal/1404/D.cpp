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

const int MAXN = 1e6 + 5;
int n;
std::vector<int> bel[MAXN],G[MAXN];
int p[MAXN];
int col[MAXN];
bool vis[MAXN];

inline void dfs(int v,int fa=0){
	vis[v] = 1;
	for(auto x:G[v]){
		if(x == fa) continue;
		if(!vis[x]){
			col[x] = col[v]^1;
			dfs(x,v);
		}
		else{
			assert(col[x]!=col[v]);
		}
	}
}

int main(){
	scanf("%d",&n);
	if(n%2 == 0){
		puts("First");
		FOR(i,1,n) printf("%d ",i);
		FOR(i,1,n) printf("%d ",i);
		puts("");std::fflush(stdout);return 0;
	}
	puts("Second");std::fflush(stdout);
	FOR(i,1,2*n) scanf("%d",p+i),bel[p[i]].pb(i);
	FOR(i,1,n){
		G[bel[i][0]].pb(bel[i][1]);
		G[bel[i][1]].pb(bel[i][0]);
	}
	FOR(i,1,n) G[i].pb(i+n),G[i+n].pb(i); 
	FOR(i,1,2*n) if(!vis[i]) dfs(i);
	int sm = 0;
	FOR(i,1,2*n) if(col[i]) (sm += i) %= (2*n);
	if(sm) FOR(i,1,2*n) col[i] ^= 1;
	FOR(i,1,2*n) if(col[i]) printf("%d ",i);puts("");std::fflush(stdout);
	return 0;
}