#include<bits/stdc++.h>
#define int long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,m,len,to[200005];
P<int,int> p[200005];
V<int> g[200005];
int fa[200005][20],dep[200005];
V<P<int,int> > v[200005];
int dfn[200005];
int cnt=0;
int get(int x){
	RE (to[x]==x)?x:(to[x]=get(to[x]));
}
int merge(int x,int y){
	x=get(x);y=get(y);
	if(x!=y){
		to[x]=y;
		RE 1;
	}else RE 0;
}
void dfs(int x,int y){
	dfn[x]=++cnt;
	for(auto u:g[x])if(u!=y){
		fa[u][0]=x;dep[u]=dep[x]+1;dfs(u,x);
		v[x].PB(MP(dfn[u],u));
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int t=dep[x]-dep[y];
	rep(i,0,20)if(t&(1<<i))x=fa[x][i];
	if(x==y)RE x;
	for(int i=19;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	RE fa[x][0];
}
int ans[200005],val[200005];
void get(int x,int y){
	if(val[x]==len)ans[x]=1;else ans[x]=0;
	for(auto u:g[x])if(u!=y){
		val[u]+=val[x];
		get(u,x);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)to[i]=i;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		if(merge(x,y)){
			g[x].PB(y);g[y].PB(x);
		}else{
			p[++len]=MP(x,y);
		}
	}
	dfs(1,-1);
	rep(i,1,20)FOR(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
	FOR(i,1,len){
		int mid=lca(p[i].F,p[i].S);
		if(mid==p[i].F||mid==p[i].S){
			if(dep[p[i].F]>dep[p[i].S])swap(p[i].F,p[i].S);
			int t=upb(ALL(v[p[i].F]),MP(dfn[p[i].S],p[i].S))-v[p[i].F].begin()-1;
			t=v[p[i].F][t].S;
			val[1]++;val[t]--;val[p[i].S]++;
		}else{
			val[p[i].F]++;val[p[i].S]++;
		}
	}
	get(1,-1);
	FOR(i,1,n)cout<<ans[i];
	RE 0;
}