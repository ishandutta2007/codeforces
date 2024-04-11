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
const int maxn=200+5;
int n,m;
char s[maxn][maxn];
int hash1(int x,int y){
	return (x-1)*m+y+1;
}
int hash2(int x,int y){
	return n*m-m+(y-1)*n+x+1;
}
struct edge{
	int from,to,cap,flow;
	edge(int u,int v,int w):from(u),to(v),cap(w),flow(0){}
};
vector<edge> edges;
vector<int> g[maxn*maxn*2];
void add_edge(int u,int v,int w){
	g[u].push_back(edges.size());
	edges.push_back(edge(u,v,w));
	g[v].push_back(edges.size());
	edges.push_back(edge(v,u,0));
}
int d[maxn*maxn*2];
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
	return d[n*m*2-n-m+1]>=0;
}
const int inf=2e9;
int cur[maxn*maxn*2];
int dfs(int u,int a){
	if(u==n*m*2-n-m+1) return a;
	int ans=0;
	for(int& i=cur[u];i<(int)g[u].size();i++){
		edge& e=edges[g[u][i]];
		if(e.flow>=e.cap||d[e.to]!=d[u]+1) continue;
		int res=dfs(e.to,min(a,e.cap-e.flow));
		ans+=res;
		e.flow+=res;
		edges[g[u][i]^1].flow-=res;
		if(a<inf) a-=res;
		if(!a) break;
	}
	return ans;
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
	n=readint();
	m=readint();
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=1;i<=n*m-m;i++) add_edge(0,i,1);
	for(int i=n*m-m+1;i<=n*m*2-n-m;i++) add_edge(i,n*m*2-n-m+1,1);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j]=='#'){
		if(i&&j&&s[i-1][j]=='#'&&s[i][j-1]=='#')
			add_edge(hash1(i,j),hash2(i,j),1);
		if(i&&j<m-1&&s[i-1][j]=='#'&&s[i][j+1]=='#')
			add_edge(hash1(i,j),hash2(i,j+1),1);
		if(i<n-1&&j&&s[i+1][j]=='#'&&s[i][j-1]=='#')
			add_edge(hash1(i+1,j),hash2(i,j),1);
		if(i<n-1&&j<m-1&&s[i+1][j]=='#'&&s[i][j+1]=='#')
			add_edge(hash1(i+1,j),hash2(i,j+1),1);
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<n;i++) for(int j=0;j<m;j++)
		if(s[i][j]=='#'&&s[i-1][j]=='#') cnt1++;
	for(int i=0;i<n;i++) for(int j=1;j<m;j++)
		if(s[i][j]=='#'&&s[i][j-1]=='#') cnt1++;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j]=='#') cnt2++;
	printf("%d\n",cnt2-cnt1+dinic());
	return 0;
}