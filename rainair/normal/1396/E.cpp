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

const int MAXN = 1e5 + 5;

struct Edge{
	int to,nxt;
}e[MAXN<<1];
int head[MAXN],bk[MAXN],cnt;

inline void add(int u,int v){
	e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int n;LL k;
int sz[MAXN],mx[MAXN],rt;

inline void dfs1(int v,int fa=0){
	sz[v] = 1;
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		dfs1(e[i].to,v);sz[v] += sz[e[i].to];
		mx[v] = std::max(mx[v],sz[e[i].to]);
	}
	mx[v] = std::max(mx[v],n-sz[v]);
	if(mx[rt] > mx[v]) rt = v;
}

LL ansl,ansr;
int tp[MAXN],dep[MAXN],deg[MAXN],fa[MAXN];
std::set<P> S[MAXN];

inline void dfs2(int v,int fa,int rr){
	sz[v] = 1;tp[v] = rr;dep[v] = dep[fa]+1;::fa[v] = fa;
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		deg[v]++;dfs2(e[i].to,v,rr);sz[v] += sz[e[i].to];
	}
	if(deg[v]) S[rr].insert(MP(dep[v],v));
	ansl += (sz[v]&1);ansr += sz[v];
}

bool vis[MAXN];
std::set<P> q;

inline void del(int v){
	if(!--deg[fa[v]]){
		S[tp[fa[v]]].erase(MP(dep[fa[v]],fa[v]));
	}
}

std::vector<int> rem;

inline void dfs3(int v,int fa=0){
	if(!vis[v]) rem.pb(v);
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		dfs3(e[i].to,v);
	}
}

int main(){
	scanf("%d%lld",&n,&k);
	FOR(i,2,n){
		int u,v;scanf("%d%d",&u,&v);
		add(u,v);
	}
	memcpy(bk,head,sizeof(bk));
	mx[0] = n;dfs1(1);sz[rt] = n;
	for(int i = head[rt];i;i = e[i].nxt){
		dfs2(e[i].to,rt,e[i].to);
		if(sz[e[i].to] > 1){
			q.insert(MP(sz[e[i].to],e[i].to));
		}
	}
	deg[rt] = 114514;
	if(k < ansl || k > ansr || (ansr-k)&1){
		puts("NO");return 0;
	}
	puts("YES");
	LL d = ansr-k;
	while(d){
		int r = q.rbegin()->se;q.erase(--q.end());
		int v,gx;std::tie(gx,v) = *S[r].rbegin();
		if(d < 2*gx){
			d >>= 1;
			v = S[r].lower_bound(MP(d,0))->se;
			std::vector<int> t;
			for(int &i = head[v];i&&t.size()<2;i = e[i].nxt) if(e[i].to != fa[v] && !vis[e[i].to]) t.pb(e[i].to);
			if(t.size() < 2) t.pb(v);
			vis[t[0]] = vis[t[1]] = 1;
			printf("%d %d\n",t[0],t[1]);
			break;
		}
		else{
			d -= 2*gx;
			std::vector<int> t;
			for(int &i = head[v];i&&t.size()<2;i = e[i].nxt) if(e[i].to != fa[v] && !vis[e[i].to]) t.pb(e[i].to);
			if(t.size() < 2) t.pb(v);
			printf("%d %d\n",t[0],t[1]);
			vis[t[0]] = vis[t[1]] = 1;
			del(t[0]);del(t[1]);
		}
		sz[r] -= 2;
		if(sz[r]) q.insert(MP(sz[r],r));
	}
	memcpy(head,bk,sizeof(head));
	dfs3(rt);
	int t = rem.size()/2;
	FOR(i,0,t-1) printf("%d %d\n",rem[i],rem[i+t]);
	return 0;
}