#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#define MN 5100000
typedef std::pair<int,int> pii;

int n,m;

typedef struct{
	int v,w;
}edge;
std::vector<edge> e[MN+5];

int id(int u,int w){
	return (u-1)*51+w;
}

void _add(int u,int v,int w){
	e[u].push_back((edge){v,w});
}

void add(int u,int v,int w){
	_add(id(u,0),id(v,w),0);
	for(int i=1;i<=50;i++)
		_add(id(u,i),id(v,0),(i+w)*(i+w));
}

int dis[MN+5];

void dij(int S){
	memset(dis,0x3f,sizeof(dis));
	dis[S] = 0;
	std::priority_queue<pii,std::vector<pii>,std::greater<pii>> pq;
	pq.push(pii(dis[S],S));
	while(!pq.empty()){
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(d!=dis[u]) continue;
		for(auto p:e[u]){
			if(d+p.w<dis[p.v]){
				pq.push(pii(dis[p.v]=d+p.w,p.v));
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	dij(id(1,0));
	for(int i=1;i<=n;i++)
		if(dis[id(i,0)]==0x3f3f3f3f)
			printf("-1 ");
		else
			printf("%d ",dis[id(i,0)]);
	puts("");
}