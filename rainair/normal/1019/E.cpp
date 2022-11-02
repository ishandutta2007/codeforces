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

const int MAXN = 3e5 + 5;

struct Node{
	LL x,y;
	Node(LL x=0,LL y=0) : x(x),y(y) {}
	
	Node operator + (const Node &t) const {
		return Node(x+t.x,y+t.y);
	}
	
	Node operator - (const Node &t) const {
		return Node(x-t.x,y-t.y);
	}
	
	long double operator * (const Node &t) const {
		return (long double)x*t.y-(long double)y*t.x;
	}
	
	bool operator < (const Node &t) const {
		return x == t.x ? y > t.y : x < t.x;
	}
};

inline void build(std::vector<Node> &v){
	std::vector<Node> t;
	std::sort(all(v));
	for(auto x:v){
		while(t.size() >= 2 && (t.back()-t[(int)t.size()-2])*(x-t.back()) >= 0.0) t.pop_back();
		t.pb(x);
	}
	v = t;
}

inline std::vector<Node> merge(std::vector<Node> a,std::vector<Node> b){
	if(a.empty()) return b;
	if(b.empty()) return a;
	std::vector<Node> res;res.pb(a[0]+b[0]);
	int i = 1,j = 1;
	while(i < a.size() && j < b.size()){
		Node v1 = a[i]-a[i-1],v2 = b[j]-b[j-1];
		if(v1*v2 <= 0.0) res.pb(res.back()+v1),i++;
		else res.pb(res.back()+v2),j++;
	}
	FOR(k,i,(int)a.size()-1) res.pb(res.back()+a[k]-a[k-1]);
	FOR(k,j,(int)b.size()-1) res.pb(res.back()+b[k]-b[k-1]);
	// res.build();
	return res;
}

struct Edge{
	int to,a,b,nxt;
}e[MAXN<<1];
int head[MAXN],cnt = 1;
std::vector<std::pair<int,P> > G[MAXN];

inline void add(int u,int v,int a,int b){
	e[++cnt] = (Edge){v,a,b,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,a,b,head[v]};head[v] = cnt;
}

int rt;
int mx[MAXN],sz[MAXN];
bool vis[MAXN];

inline void getroot(int v,int fa=0){
	sz[v] = 1;
	for(int i = head[v];i;i = e[i].nxt){
		if(vis[i>>1] || e[i].to == fa) continue;
		getroot(e[i].to,v);
		sz[v] += sz[e[i].to];
		mx[i>>1] = std::max(sz[e[i].to],mx[0]-sz[e[i].to]);
		if(mx[i>>1] < mx[rt]) rt = i>>1;
	}
}

LL sma[MAXN],smb[MAXN];
std::vector<Node> S;

inline void dfs(int v,int fa=0){
	S.pb(Node(-sma[v],smb[v]));
	for(int i = head[v];i;i = e[i].nxt){
		if(vis[i>>1] || e[i].to == fa) continue;
		sma[e[i].to] = smb[e[i].to] = 0;
		sma[e[i].to] += sma[v]+e[i].a;
		smb[e[i].to] += smb[v]+e[i].b;
		dfs(e[i].to,v);
	}
}

std::vector<Node> all;

inline void work(int edge){
	if(!edge) return;
	vis[edge] = 1;
	int u = e[edge<<1].to,v = e[edge<<1|1].to;
	// DEBUG(edge);DEBUG(u);DEBUG(v);
	sma[u] = e[edge<<1].a;smb[u] = e[edge<<1].b;
	sma[v] = 0;smb[v] = 0;
	std::vector<Node> ls,rs;
	S.clear();dfs(u);ls = S;
	S.clear();dfs(v);rs = S;
	build(ls);build(rs);
	ls = merge(ls,rs);for(auto x:ls) all.pb(x);
	// exit(0);
	ls.clear();rs.clear();
	rt = 0;mx[0] = sz[u];getroot(u);work(rt);
	rt = 0;mx[0] = sz[v];getroot(v);work(rt);
}

int n,m;

inline LL calc(Node v,LL x){
	return -v.x*x+v.y;
}

inline void rebuild(int v,int fa=0){
	int las = v,tmp = 0;
	for(auto x:G[v]){
		if(x.fi == fa) continue;
		add(las,x.fi,x.se.fi,x.se.se);
		++n;add(las,n,0,0);las = n;
	}
	for(auto x:G[v]){
		if(x.fi == fa) continue;
		rebuild(x.fi,v);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	if(n == 1){
		FOR(i,1,m) printf("%d ",0);
		puts("");return 0;
	}
	FOR(i,2,n){
		int u,v,a,b;scanf("%d%d%d%d",&u,&v,&a,&b);
		G[u].pb(MP(v,MP(a,b)));G[v].pb(MP(u,MP(a,b)));
		// add(u,v,a,b);
	}
	rebuild(1);
	mx[rt = 0] = n;getroot(1);
	work(rt);
	build(all);
	// for(auto x:all) DEBUG(x.x),DEBUG(x.y);
	FOR(i,0,m-1){
		while(all.size() >= 2 && calc(all.back(),i) <= calc(all[(int)all.size()-2],i)) all.pop_back();
		printf("%lld ",calc(all.back(),i));
	}
	puts("");
	return 0;
}