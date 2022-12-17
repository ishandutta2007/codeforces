#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e3+5;
int n,m,a[maxn];
vector<int> g[maxn];
const int inf=2e9;
namespace flow{
	vector<int> p;
	struct edge{
		int from,to,cap,flow;
	};
	vector<edge> edges;
	vector<int> g[maxn];
	void add_edge(int u,int v,int w){
		g[u].push_back(edges.size());
		edges.push_back({u,v,w,0});
		g[v].push_back(edges.size());
		edges.push_back({v,u,0,0});
	}
	int d[maxn];
	bool bfs(){
		for(int i:p) d[i]=-1;
		queue<int> q;
		d[0]=0;
		q.push(0);
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int i:g[u]){
				edge& e=edges[i];
				if(e.flow>=e.cap) continue;
				if(d[e.to]<0){
					d[e.to]=d[u]+1;
					q.push(e.to);
				}
			}
		}
		return d[n+1]>=0;
	}
	int cur[maxn];
	int dfs(int u,int a){
		if(u==n+1) return a;
		int flow=0;
		for(int& i=cur[u];i<(int)g[u].size();i++){
			edge& e=edges[g[u][i]];
			if(e.flow>=e.cap||d[e.to]!=d[u]+1) continue;
			int f=dfs(e.to,e.cap<inf?min(a,e.cap-e.flow):a);
			flow+=f;
			e.flow+=f;
			edges[g[u][i]^1].flow-=f;
			if(a<inf) a-=f;
			if(!a) break;
		}
		return flow;
	}
	void dinic(){
		while(bfs()){
			for(int i:p) cur[i]=0;
			dfs(0,inf);
		}
	}
}
bool vis[maxn];
int b[maxn];
void solve(int l,int r,vector<int> p){
	if(!p.size()) return;
	for(int i:p) vis[i]=1;
	for(int i:p) vector<int>().swap(flow::g[i]);
	vector<int>().swap(flow::g[0]);
	vector<int>().swap(flow::g[n+1]);
	vector<flow::edge>().swap(flow::edges);
	flow::p=p;
	flow::p.push_back(0);
	flow::p.push_back(n+1);
	for(int i:p) for(int j:g[i])
		if(vis[j]) flow::add_edge(i,j,inf);
	int mid=l+(r-l)/2;
	for(int i:p){
		int res;
		if(r-l==1) res=abs(r-a[i])-abs(l-a[i]);
		else res=mid>=a[i]?1:-1;
		if(res<0) flow::add_edge(0,i,-res);
		else flow::add_edge(i,n+1,res);
	}
	flow::dinic();
	vector<int> pl,pr;
	for(int i:p)
		if(flow::d[i]>=0) pr.push_back(i);
		else pl.push_back(i);
	for(int i:p) vis[i]=0;
	if(r-l==1){
		for(int i:pl) b[i]=l;
		for(int i:pr) b[i]=r;
	}
	else{
		solve(l,mid,pl);
		solve(mid,r,pr);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++){
		int u,v;
		u=readint();
		v=readint();
		g[u].push_back(v);
	}
	vector<int> p;
	for(int i=1;i<=n;i++) p.push_back(i);
	solve(1,1e9,p);
	for(int i=1;i<=n;i++) printf("%d ",b[i]);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}