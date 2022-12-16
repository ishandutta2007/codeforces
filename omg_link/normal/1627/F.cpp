#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#define MK 600
#define MV MK*MK

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

using std::priority_queue;
using std::vector;
using std::greater;
using std::min;

using std::swap;

const int INF = 0x3fffffff;

int n,k;
int d[MV+5][4];
int dis[MV+5];

int getId(int x,int y){
	return x*(k+1)+y;
}

void addVal(int r1,int c1,int r2,int c2){
	if(r1==r2){
		if(c1>c2) swap(c1,c2);
		int v1 = getId(r1-1,c1);
		int v2 = getId(r1,c1);
		d[v1][DOWN]++;
		d[v2][UP]++;
	}
	if(c1==c2){
		if(r1>r2) swap(r1,r2);
		int v1 = getId(r1,c1-1);
		int v2 = getId(r1,c1);
		d[v1][RIGHT]++;
		d[v2][LEFT]++;
	}
}

void dijkstra(int S){
	for(int i=0;i<(k+1)*(k+1);i++){
		dis[i] = INF;
	}
	using pii = std::pair<int,int>;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	dis[S] = 0;
	pq.push({dis[S],S});
	while(!pq.empty()){
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(d!=dis[u]) continue;
		int x = u/(k+1);
		int y = u%(k+1);
		auto upd = [&](int x,int y,int d){
			if(x<0||x>k||y<0||y>k) return;
			int id = getId(x,y);
			if(d<dis[id]){
				dis[id] = d;
				pq.push({dis[id],id});
			}
		};
		upd(x-1,y,d+::d[u][UP]);
		upd(x+1,y,d+::d[u][DOWN]);
		upd(x,y-1,d+::d[u][LEFT]);
		upd(x,y+1,d+::d[u][RIGHT]);
	}
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int r1,c1,r2,c2;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		addVal(r1,c1,r2,c2);
		addVal(k-r1+1,k-c1+1,k-r2+1,k-c2+1);
	}
	dijkstra(getId(k/2,k/2));
	int ans = INF;
	for(int i=0;i<=k;i++)
		ans = min({ans,dis[getId(i,0)],dis[getId(0,i)],dis[getId(i,k)],dis[getId(k,i)]});
	printf("%d\n",n-ans);
	memset(d,0,sizeof(int)*(k+1)*(k+1)*4);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}