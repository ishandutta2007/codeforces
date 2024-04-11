#include<bits/stdc++.h>

#define fi first
#define se second
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
const int MAXN = 1e5 + 5;

namespace Flow{
	struct Edge{
		int to,w,nxt;
	}e[MAXN<<1];
	int head[MAXN],cur[MAXN],cnt=1;
	int dep[MAXN];
	int S,T,N;

	inline void add(int u,int v,int w){
		e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
		e[++cnt] = (Edge){u,0,head[v]};head[v] = cnt;
	}

	inline bool bfs(){
		FOR(i,0,N) cur[i] = head[i],dep[i] = 0;
		std::queue<int> q;q.push(S);dep[S] = 1;
		while(!q.empty()){
			int v = q.front();q.pop();
			for(int i = head[v];i;i = e[i].nxt){
				if(e[i].w > 0 && !dep[e[i].to]){
					dep[e[i].to] = dep[v] + 1;
					if(e[i].to == T) return true;
					q.push(e[i].to);
				}
			}
		}
		return dep[T];
	}

	inline int dfs(int v,int flow=1e9){
		if(v == T) return flow;
		if(!flow) return 0;
		int ans = 0;
		for(int &i = cur[v];i;i = e[i].nxt){
			if(e[i].w > 0 && dep[e[i].to] == dep[v] + 1){
				int t = dfs(e[i].to,std::min(flow,e[i].w));
				if(t>0){
					ans += t;flow -= t;
					e[i].w -= t;e[i^1].w += t;
					if(!flow) break;
				}
			}
		}
		return ans;
	}

	inline int Dinic(){
		int ans = 0,t = 0;
		while(bfs()) while((t=dfs(S))) ans += t;
		return ans;
	}
};
using namespace Flow;
std::vector<int> to[MAXN];
int a[MAXN];
int n;

signed main(){
	scanf("%lld",&n);
	FOR(i,1,n){
		int sz;scanf("%lld",&sz);
		while(sz--){int x;scanf("%lld",&x);to[i].pb(x);}
	}
	FOR(i,1,n) scanf("%lld",a+i),a[i] = -a[i];
	// >=
	// -inf +inf
	int ans = 0;N = 2*n;S = ++N;T = ++N;
	FOR(i,1,n){
		for(auto x:to[i]) add(i,n+x,1e12);
		a[i] += 1e9;
		if(a[i] > 0) ans += a[i],add(S,i,a[i]);
		else add(i,T,-a[i]);
		add(i+n,T,1e9);
	}
	//DEBUG(ans);
//	int t = Dinic();
//	ans -= t;DEBUG(t);
	ans -= Dinic();
	printf("%lld\n",-ans);
	return 0;
}