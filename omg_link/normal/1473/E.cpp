#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#define MN (200000*4)
typedef long long LL;

int n,m;
struct edge{
	int to,val;
};
std::vector<edge> e[MN+5];

int id(int u,int id1,int id2){
	return n*(id1<<1|id2)+u;
}

void add(int u,int v,int w){
	e[u].push_back((edge){v,w});
}

typedef std::pair<LL,int> pii;

LL dis[MN+5];

void dij(int S){
	memset(dis,0x3f,sizeof(dis));
	dis[S] = 0;
	std::priority_queue<pii,std::vector<pii>,std::greater<pii>> pq;
	pq.push(pii(dis[S],S));
	while(!pq.empty()){
		pii p = pq.top();
		pq.pop();
		int u = p.second;
		LL d = p.first;
		if(d!=dis[u]) continue;
		for(auto e: ::e[u]){
			int to = e.to;
			int val = e.val;
			if(d+val<dis[to]){
				dis[to] = d+val;
				pq.push(pii(dis[to],to));
			}
		}
	}
}

void ADD(int u,int v,int w){
	add(id(u,0,0),id(v,0,0),w);
	add(id(u,0,0),id(v,0,1),0);
	add(id(u,0,0),id(v,1,0),2*w);
	add(id(u,0,0),id(v,1,1),w);
	add(id(u,0,1),id(v,0,1),w);
	add(id(u,0,1),id(v,1,1),2*w);
	add(id(u,1,0),id(v,1,0),w);
	add(id(u,1,0),id(v,1,1),0);
	add(id(u,1,1),id(v,1,1),w);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		ADD(u,v,w),ADD(v,u,w);
	}
	dij(id(1,0,0));
	for(int i=2;i<=n;i++)
		printf("%lld ",dis[id(i,1,1)]);
}