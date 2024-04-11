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

const int MAXN = 2e5 + 5;
int n,k;

struct Edge{
	int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
	e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int dep[MAXN],sz[MAXN];
std::vector<int> S;

inline void dfs(int v,int fa=0){
	dep[v] = dep[fa]+1;sz[v] = 1;
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		dfs(e[i].to,v);
		sz[v] += sz[e[i].to];
	}
	S.pb(sz[v]-dep[v]);
}

int main(){
	scanf("%d%d",&n,&k);
	FOR(i,2,n){
		int u,v;scanf("%d%d",&u,&v);
		add(u,v);
	}
	dfs(1);
	std::sort(all(S));std::reverse(all(S)); 
	LL ans = 0;
	FOR(i,0,n-k-1) ans += S[i];
	printf("%lld\n",ans);
	return 0;
}