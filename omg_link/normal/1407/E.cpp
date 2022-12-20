#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#define MN 500000

int n,m,tp[MN+5],dist[MN+5];

struct edge{
	int to,tp;
	edge(){}
	edge(int to,int tp){
		this->to = to;
		this->tp = tp;
	}
};

std::vector<edge> ein[MN+5],eout[MN+5];

int main(){
	memset(tp,0xff,sizeof(tp));
	memset(dist,0xff,sizeof(dist));
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,tp;i<=m;i++){
		scanf("%d%d%d",&u,&v,&tp);
		eout[u].push_back(edge(v,tp));
		ein[v].push_back(edge(u,tp));
	}
	std::queue<int> q;
	dist[n] = 0;
	for(q.push(n);!q.empty();q.pop()){
		int u = q.front();
		for(auto e:ein[u]){
			if(tp[e.to]==-1){
				tp[e.to] = e.tp^1;
			}
			if(dist[e.to]==-1&&tp[e.to]==e.tp){
				dist[e.to] = dist[u]+1;
				q.push(e.to);
			}
		}
	}
	printf("%d\n",dist[1]);
	for(int i=1;i<=n;i++)
		printf("%d",tp[i]==-1?0:tp[i]);
}