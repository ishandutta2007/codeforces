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
const int maxn=50+5;
int n,m,q;
struct edge{
	int from,to,cap,flow,cost;
	edge(int u,int v,int w,int f):from(u),to(v),cap(w),flow(0),cost(f){}
};
vector<edge> edges;
vector<int> g[maxn];
void add_edge(int u,int v,int w,int f){
	g[u].push_back(edges.size());
	edges.push_back(edge(u,v,w,f));
	g[v].push_back(edges.size());
	edges.push_back(edge(v,u,0,-f));
}
const int inf=2e9;
int d[maxn],p[maxn];
bool inq[maxn];
bool spfa(){
	for(int i=2;i<=n;i++) d[i]=inf;
	queue<int> q;
	q.push(1);
	inq[1]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i:g[u]){
			edge& e=edges[i];
			if(e.flow>=e.cap) continue;
			if(d[e.to]>d[u]+e.cost){
				d[e.to]=d[u]+e.cost;
				p[e.to]=i;
				if(!inq[e.to]){
					q.push(e.to);
					inq[e.to]=1;
				}
			}
		}
	}
	return d[n]<inf;
}
int f[maxn];
int mcmf(){
	int flow=0,cost=0;
	while(spfa()){
		flow++;
		cost+=d[n];
		f[flow]=cost;
		int u=n;
		while(u!=1){
			edges[p[u]].flow++;
			edges[p[u]^1].flow--;
			u=edges[p[u]].from;
		}
	}
	return flow;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=0;i<m;i++){
		int u,v,w;
		u=readint();
		v=readint();
		w=readint();
		add_edge(u,v,1,w);
	}
	int flow=mcmf();
	q=readint();
	while(q--){
		int x=readint();
		double ans=1.0/0.0;
		for(int i=0;i<=flow;i++) ans=min(ans,1.0*(f[i]+x)/i);
		printf("%.10f\n",ans);
	}
	return 0;
}