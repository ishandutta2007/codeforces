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

const int MAXN = 1000+5;
char str[MAXN];
int n;
#ifdef RainAir
std::vector<int> T[MAXN];
bool vis[MAXN];
inline void dfs(int v,int lim,int d=0,int fa=0){
	if(d > lim) return;
	if(fa) vis[v] = 1;
	for(auto x:T[v]){
		if(x == fa) continue;
		dfs(x,lim,d+1,v);
	}
}
#endif

inline std::vector<int> query(std::vector<int> d){
	std::vector<int> ans;
	#ifdef RainAir
	FOR(i,1,n) vis[i] = 0;
	FOR(i,1,n) dfs(i,d[i-1]);
	FOR(i,1,n) ans.pb(vis[i]);return ans;
	#endif
	printf("? ");for(auto x:d) printf("%d ",x);puts("");std::fflush(stdout);
	scanf("%s",str+1);FOR(i,1,n) ans.pb(str[i]-'0');
	return ans;
}

std::vector<int> G[MAXN];// 1i
std::vector<int> node[MAXN*50];
int tot = 1;

struct Node{
	int l,r,id;
	Node(int l=0,int r=0,int id=0) : l(l),r(r),id(id) {}
	inline bool operator < (const Node &t) const {
		return l < t.l;
	}
};

int fa[MAXN];

inline void work(std::vector<int> id,int bit){
	std::vector<int> d;d.resize(n);
	for(auto x:id){
		for(auto y:G[x-1]) if((y>>bit)&1) d[y-1] = 1;
	}
	std::vector<int> a;a = query(d);
	for(auto x:id){
		for(auto y:G[x]) fa[y] |= (a[y-1]<<bit);
	}
}

bool tag[MAXN];

int main(){
	scanf("%d",&n);
	// BEGIN DEBUG
	#ifdef RainAir
	FOR(i,2,n){
		int u,v;scanf("%d%d",&u,&v);
		T[u].pb(v);T[v].pb(u);
	}
	#endif
	// END   DEBUG
	std::vector<Node> now;
	// 
	G[0].pb(1);
	// std::vector<int> _;FOR(i,1,n) _.pb(0);
	// std::vector<int>__=query(_);for(auto x:__)DEBUG(x);
	// exit(0);
	now.pb(Node(0,n,1));FOR(i,2,n) node[tot].pb(i);
	while(!now.empty()){
		// puts("------");
		std::vector<Node> v1,v2;std::sort(all(now));
		// for(auto x:now) printf("%d %d %d\n",x.l,x.r,x.id);
		for(int i = 0;i < now.size();i += 2){
			v1.pb(now[i]);
			if(i+1 < now.size()) v2.pb(now[i+1]);
		}
		std::vector<int> d,a1,a2;d.resize(n);now.clear();
		CLR(tag,0);
		for(auto x:v1){
			int mid = (x.l+x.r)>>1;
			assert(x.l < x.r-1);
			for(auto y:G[x.l]) d[y-1] = mid-x.l-1,tag[y-1] = 1;
		}
		a1 = query(d);FOR(i,0,n-1) if(tag[i]) d[i]++;
		a2 = query(d);
		for(auto x:v1){
			int mid = (x.l+x.r)>>1;
			Node ls = Node(x.l,mid,++tot),rs = Node(mid,x.r,++tot);
			for(auto y:node[x.id]){
				if(!a1[y-1] && a2[y-1]) G[mid].pb(y);
				else if(a1[y-1]) node[ls.id].pb(y);
				else node[rs.id].pb(y);
			}
			if(ls.l+1 < ls.r) now.pb(ls);
			if(rs.l+1 < rs.r) now.pb(rs);
		}
		d.clear();d.resize(n);CLR(tag,0);
		for(auto x:v2){
			int mid = (x.l+x.r)>>1;
			assert(x.l < x.r-1);
			for(auto y:G[x.l]) d[y-1] = mid-x.l-1,tag[y-1] = 1;
		}
		a1 = query(d);FOR(i,0,n-1) if(tag[i]) d[i]++;
		a2 = query(d);
		for(auto x:v2){
			int mid = (x.l+x.r)>>1;
			Node ls = Node(x.l,mid,++tot),rs = Node(mid,x.r,++tot);
			for(auto y:node[x.id]){
				// printf("%d\n",y);
				// printf("%d %d\n",a1[y-1],a2[y-1]);
				if(!a1[y-1] && a2[y-1]) G[mid].pb(y);
				else if(a1[y-1]) node[ls.id].pb(y);
				else node[rs.id].pb(y);
			}
			if(ls.l+1 < ls.r) now.pb(ls);
			if(rs.l+1 < rs.r) now.pb(rs);
		}
		// exit(0);
		// DEBUG(1);
	}
	// FOR(i,0,4){
		// for(auto x:G[i]) printf("%d ",x);
		// puts("");
	// }
	// father
	FOR(i,0,9){
		std::vector<int> v1,v2,v3;
		for(int i = 1;i < n;i += 3){
			v1.pb(i);
			if(i+1 < n) v2.pb(i+1);
			if(i+2 < n) v3.pb(i+2);
		}
		work(v1,i);
		work(v2,i);work(v3,i);
	}
	puts("!");
	// DEBUG(fa[4]);DEBUG(fa[5]);
	FOR(i,2,n) printf("%d %d\n",fa[i],i);
	std::fflush(stdout);
	return 0;
}