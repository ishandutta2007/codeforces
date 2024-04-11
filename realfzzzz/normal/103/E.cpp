#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
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
const int maxn=300+5;
int n;
typedef long long ll;
struct edge{
	int from,to;
	ll cap,flow;
	edge(int u,int v,ll w):from(u),to(v),cap(w),flow(0){}
};
vector<edge> edges;
vector<int> g[maxn*2];
void add_edge(int u,int v,ll w){
	g[u].push_back(edges.size());
	edges.push_back(edge(u,v,w));
	g[v].push_back(edges.size());
	edges.push_back(edge(v,u,0));
}
int d[maxn*2];
bool bfs(){
	memset(d,-1,sizeof(d));
	queue<int> q;
	d[0]=0;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i:g[u]){
			edge& e=edges[i];
			if(e.flow>=e.cap||d[e.to]>=0) continue;
			d[e.to]=d[u]+1;
			q.push(e.to);
		}
	}
	return d[n*2+1]>=0;
}
const ll inf=9e18;
int cur[maxn*2];
ll dfs(int u,ll a){
	if(u==n*2+1) return a;
	ll ans=0;
	for(int& i=cur[u];i<(int)g[u].size();i++){
		edge& e=edges[g[u][i]];
		if(e.flow>=e.cap||d[e.to]!=d[u]+1) continue;
		ll res=dfs(e.to,min(a,e.cap-e.flow));
		ans+=res;
		e.flow+=res;
		edges[g[u][i]^1].flow-=res;
		if(a<inf) a-=res;
		if(!a) break;
	}
	return ans;
}
ll dinic(){
	ll ans=0;
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
	n=readint();
	for(int i=1;i<=n;i++){
		int m=readint();
		while(m--) add_edge(i,readint()+n,inf);
	}
	ll res=0;
	for(int i=1;i<=n;i++){
		int v=readint();
		add_edge(0,i,2e9-v);
		res+=2e9-v;
	}
	for(int i=1;i<=n;i++) add_edge(i+n,n*2+1,2e9);
	printf("%lld\n",min(0ll,dinic()-res));
	return 0;
}