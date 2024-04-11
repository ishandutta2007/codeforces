#include<bits/stdc++.h>
#define ll long long
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
int n,m,q,w[100005];
V<int> g[100005],v[200005]; 
bool in[100005];
int cnt=0,dfn[200005],low[100005],cntcol;
stack<int> st;
void dfs1(int x,int y){
	in[x]=1;st.emplace(x);
	dfn[x]=low[x]=++cnt;
	for(auto u:g[x])if(u!=y){
		if(dfn[u]){
			if(in[u])gmin(low[x],dfn[u]);
		}else{
			dfs1(u,x);
			gmin(low[x],low[u]);
			if(low[u]>=dfn[x]){
				++cntcol;
				v[cntcol].PB(x);v[x].PB(cntcol);
				while(st.top()!=u){
					in[st.top()]=0;
					v[st.top()].PB(cntcol);
					v[cntcol].PB(st.top());
					st.pop();
				}
				in[u]=0;
				v[u].PB(cntcol);v[cntcol].PB(u);st.pop();
			}
		}
	}
}
multiset<int> s[200005];
int top[200005],siz[200005],son[200005],dep[200005],fa[200005];
int mini[1<<19];
void dfs2(int x,int y){
	siz[x]=1;
	for(auto u:v[x])if(u!=y){
		dep[u]=dep[x]+1;fa[u]=x;
		dfs2(u,x);
		siz[x]+=siz[u];
		if(siz[u]>siz[son[x]])son[x]=u;
	}
}
void dfs3(int x,int y,int tp){
	top[x]=tp;
	dfn[x]=++cnt;
	if(son[x])dfs3(son[x],x,tp);
	for(auto u:v[x])if(u!=y&&u!=son[x]){
		dfs3(u,x,u);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];else y=fa[top[y]];
	}
	if(dep[x]<dep[y])RE x;else RE y;
}
void update(int x,int l,int r,int to,int val){
	if(l==r){
		mini[x]=val;RE;
	}
	int mid=(l+r)>>1;
	if(mid>=to)update(lc,l,mid,to,val);else update(rc,mid+1,r,to,val);
	mini[x]=min(mini[lc],mini[rc]);
}
int get(int x,int l,int r,int tl,int tr){
	if(l>tr||tl>r)RE 2e9;
	if(l>=tl&&r<=tr)RE mini[x];
	int mid=(l+r)>>1;
	RE min(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
}
int get(int x,int y){
	int re=2e9;
	while(1){
		if(dep[top[x]]<=dep[y])RE min(re,get(1,1,cntcol,dfn[y],dfn[x]));
		gmin(re,get(1,1,cntcol,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	RE -1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	FOR(i,1,n)cin>>w[i];
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		g[x].PB(y);
		g[y].PB(x);
	}
	cntcol=n;
	dfs1(1,-1);
	cnt=0;
	dfs2(1,-1);
	dfs3(1,-1,1);
	FOR(i,2,n)s[fa[i]].emplace(w[i]);
	FOR(i,n+1,cntcol)update(1,1,cntcol,dfn[i],*s[i].begin());
	FOR(i,1,n)update(1,1,cntcol,dfn[i],w[i]);
	FOR(i,1,q){
		char tp;
		int a,b;
		cin>>tp>>a>>b;
		if(tp=='C'){
			if(a!=1){
				s[fa[a]].erase(s[fa[a]].find(w[a]));
				s[fa[a]].emplace(b);
				update(1,1,cntcol,dfn[fa[a]],*s[fa[a]].begin());
			}
			w[a]=b;
			update(1,1,cntcol,dfn[a],w[a]);
		}else{
			int t=lca(a,b);
			int ans=min(get(a,t),get(b,t));
			if(t>n)gmin(ans,w[fa[t]]);
			cout<<ans<<'\n';
		}
	}
	RE 0;
}