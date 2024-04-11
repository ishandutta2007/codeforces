#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 5100005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m;
vector<pii>G[MN];
int id(int x,int y){return 51*(x-1)+y;}
int vis[MN],dis[MN];
void Dijkstra(int s){
	priority_queue<pii>pq;
	F(i,1,51*n)dis[i]=inf;
	dis[s]=0,pq.push({0,s});
	while(!pq.empty()){
		pii p=pq.top();pq.pop();
		int u=p.se,d=p.fi;
		if(vis[u])continue;
		vis[u]=1;
		for(pii e:G[u]){
			int v=e.fi,w=e.se;
			if(dis[v]>d+w){
				dis[v]=d+w;
				pq.push({-dis[v],v});
			}
		}
	}
}
int main(){int x,y,z;
	scanf("%d%d",&n,&m);
	F(i,1,m){
		scanf("%d%d%d",&x,&y,&z);
		G[id(x,0)].pb({id(y,z),0});
		G[id(y,0)].pb({id(x,z),0});
		F(j,1,50)
			G[id(x,j)].pb({id(y,0),(j+z)*(j+z)}),
			G[id(y,j)].pb({id(x,0),(j+z)*(j+z)});
	}
	Dijkstra(id(1,0));
	F(i,1,n)printf("%d%c",dis[id(i,0)]>=inf?-1:dis[id(i,0)]," \n"[i==n]);
	return 0;
}