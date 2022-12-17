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
const int maxn=200+5,maxa=1e4+5;
bool np[maxa*2];
vector<int> p;
int n,a[maxn];
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
	return d[n+1]>=0;
}
int cur[maxn*2];
const int inf=2e9;
int dfs(int u,int a){
	if(u==n+1) return a;
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
bool vis[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=2;i<maxa*2;i++){
		if(!np[i]) p.push_back(i);
		for(int j:p){
			if(1ll*i*j>=maxa*2) break;
			np[i*j]=1;
			if(i%j==0) break;
		}
	}
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++)
		if(a[i]%2==1){
			add_edge(0,i,2);
			for(int j=1;j<=n;j++)
				if(!np[a[i]+a[j]]) add_edge(i,j,1);
		}
		else add_edge(i,n+1,2);
	if(dinic()<n){
		printf("Impossible\n");
		return 0;
	}
	vector<vector<int>> ans;
	for(int i=1;i<=n;i++) if(!vis[i]){
		int u=i;
		vector<int> res;
		bool flag;
		do{
			res.push_back(u);
			vis[u]=1;
			flag=0;
			for(int j:g[u]){
				edge& e=edges[j];
				if(e.flow&&e.to>0&&e.to<=n&&!vis[e.to]){
					u=e.to;
					flag=1;
					break;
				}
			}
		}while(flag);
		ans.push_back(res);
	}
	printf("%d\n",(int)ans.size());
	for(auto i:ans){
		printf("%d ",(int)i.size());
		for(int j:i) printf("%d ",j);
		printf("\n");
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}