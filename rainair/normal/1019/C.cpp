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

struct Edge{
	int to,nxt;
}e[MAXN];
int head[MAXN],cnt;

inline void add(int u,int v){
	e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
}

int n,m;
bool vis[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);
		add(u,v);
	}
	FOR(v,1,n){
		if(vis[v]) continue;
		for(int i = head[v];i;i = e[i].nxt){
			if(e[i].to > v) vis[e[i].to] = 1;
		}
	}
	ROF(v,n,1){
		if(vis[v]) continue;
		for(int i = head[v];i;i = e[i].nxt){
			if(e[i].to < v) vis[e[i].to] = 1;
		}
	}
	std::vector<int> ans;
	FOR(i,1,n) if(!vis[i]) ans.pb(i);
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d ",x);
	return 0;
}