#include<bits/stdc++.h>
#define int long long
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
using namespace std;
V<V<char> > c;
V<V<int> > p;
int fa[400005];
int getfa(int x){
	if(x==fa[x])RE x;
	else RE fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	x=getfa(x);y=getfa(y);
	fa[x]=y;
}
int lst[400005],low[400005],to[400005],cnt,cntcol,col[400005];
bool f[400005],vis[400005],in[400005];
V<int> v[400004],g[400005];
stack<int> s;
void add(int x,int y){
	v[y].PB(x);
}
void dfs(int x){
	s.emplace(x);
	low[x]=to[x]=++cnt;vis[x]=in[x]=1;
	for(auto u:v[x]){
		if(vis[u]){
			if(in[u])gmin(to[x],low[u]);
		}else{
			dfs(u);
			gmin(to[x],to[u]);
		}
	}
	if(low[x]==to[x]){
		cntcol++;
		while(s.top()!=x){
			col[s.top()]=cntcol;
			in[s.top()]=0;
			s.pop();
		}
		in[x]=0;
		col[x]=cntcol;
		s.pop();
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	rep(i,0,n*m)fa[i]=i; 
	c.resize(n);
	p.resize(n);
	rep(i,0,n){
		c[i].resize(m);
		p[i].resize(m);
		rep(j,0,m){
			cin>>c[i][j];
			if(i&&c[i][j]=='#'&&c[i-1][j]=='#')merge(i*m+j,(i-1)*m+j);
			if(j&&c[i][j]=='#'&&c[i][j-1]=='#')merge(i*m+j,i*m+(j-1));
		}
	}
	V<int> node;
	rep(i,0,n*m)if(c[i/m][i%m]=='#'&&getfa(i)==i)f[i]=1,node.PB(i);
	rep(i,0,n)rep(j,0,m)p[i][j]=getfa(i*m+j),fa[i*m+j]=i*m+j;
	rep(i,0,m)lst[i]=-1;
	rep(i,0,n){
		rep(j,0,m){
			if(c[i][j]=='#'){
				if(j&&lst[j-1]!=-1&&lst[j-1]!=p[i][j])add(p[i][j],lst[j-1]);
				if(lst[j]!=-1&&lst[j]!=p[i][j])add(p[i][j],lst[j]);
				if(j<m-1&&lst[j+1]!=-1&&lst[j+1]!=p[i][j])add(p[i][j],lst[j+1]);
				lst[j]=p[i][j];
			}
		}
	}
	int ans=0;
	for(auto u:node)if(!vis[u])dfs(u);
	for(auto u:node){
		for(auto tu:v[u]){
			if(col[u]!=col[tu])g[col[tu]].PB(1);
		}
	}
	FOR(i,1,cntcol)ans+=g[i].empty();
	cout<<ans;
	RE 0;
}