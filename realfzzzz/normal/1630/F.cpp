#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=5e4+5;
int n,a[maxn],p[maxn];
vector<int> fac[maxn];
struct edge{
	int from,to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn*4];
void add_edge(int u,int v,int w){
	g[u].push_back(edges.size());
	edges.push_back({u,v,w,0});
	g[v].push_back(edges.size());
	edges.push_back({v,u,0,0});
}
int d[maxn*4];
bool bfs(){
	memset(d,-1,sizeof(d));
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
	return d[n*4+1]>=0;
}
int cur[maxn*4];
const int inf=2e9;
int dfs(int u,int a){
	if(u==n*4+1) return a;
	int flow=0;
	for(int& i=cur[u];i<(int)g[u].size();i++){
		edge& e=edges[g[u][i]];
		if(e.flow>=e.cap||d[e.to]!=d[u]+1) continue;
		int f=dfs(e.to,min(a,e.cap-e.flow));
		flow+=f;
		e.flow+=f;
		edges[g[u][i]^1].flow-=f;
		if(a<inf) a-=f;
		if(!a) break;
	}
	return flow;
}
int dinic(){
	int ans=0;
	while(bfs()){
		memset(cur,0,sizeof(cur));
		ans+=dfs(0,inf);
	}
	return ans;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=1;i<maxn;i++)
		for(int j=2;i*j<maxn;j++)
			fac[i*j].push_back(i);
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) p[a[i]]=i;
		vector<edge>().swap(edges);
		for(int i=0;i<=n*4+1;i++)
			vector<int>().swap(g[i]);
		for(int i=1;i<=n;i++){
			add_edge(0,i,1);
			add_edge(0,n+i,1);
			add_edge(i,n*3+i,1);
			for(int j:fac[a[i]]) if(p[j]){
				add_edge(i,n*2+p[j],1);
				add_edge(n+i,n*3+p[j],1);
			}
			add_edge(n*2+i,n*4+1,1);
			add_edge(n*3+i,n*4+1,1);
		}
		printf("%d\n",dinic()-n);
		for(int i=1;i<=n;i++) p[a[i]]=0;
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}