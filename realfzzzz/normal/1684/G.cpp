#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
const int maxn=1e3+5;
int n,m,a[maxn];
struct edge{
	int to,cap,flow;
};
vector<edge> edges;
vector<int> g[maxn];
void add_edge(int u,int v,int w){
	g[u].push_back(edges.size());
	edges.push_back({v,w,0});
	g[v].push_back(edges.size());
	edges.push_back({u,0,0});
}
int d[maxn];
bool bfs(){
	for(int i=1;i<=n+1;i++) d[i]=-1;
	queue<int> q;
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
const int inf=2e9;
int cur[maxn];
int dfs(int u,int a){
	if(u==n+1) return a;
	int flow=0;
	for(int& i=cur[u];i<(int)g[u].size();i++){
		edge& e=edges[g[u][i]];
		if(e.flow>=e.cap||d[e.to]!=d[u]+1) continue;
		int f=dfs(e.to,min(a,e.cap-e.flow));
		e.flow+=f;
		edges[g[u][i]^1].flow-=f;
		flow+=f;
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
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i]*3ll>m){
			cnt++;
			for(int j=1;j<=n;j++)
				if(a[i]*2ll+a[j]<=m&&a[i]%a[j]==0) add_edge(i,j,1);
			add_edge(0,i,1);
		}
		else add_edge(i,n+1,1);
	if(dinic()<cnt){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",n-cnt);
	for(int i=1;i<=n;i++){
		int v=-1;
		for(int j:g[i]){
			edge& e=edges[j];
			if(e.to&&e.to<=n&&e.flow) v=e.to;
		}
		if(a[i]*3ll>m) printf("%d %d\n",a[i]*2+a[v],a[i]+a[v]);
		else if(v<0) printf("%d %d\n",a[i]*3,a[i]*2);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}