#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll inf;

int n,m,k;
ll dis[N];
vector<pair<int,int>>e[N];
struct point {
	ll x,y;
	point operator -(const point &a)const {
		return (point) {
			x-a.x,y-a.y
		};
	}
	ll operator *(const point &a)const {
		return x*a.y-a.x*y;
	}
}st[N];
ll calc(point a,point b) {
	return a.x*b.x+a.y+b.y;
}
bool vis[N];
void dijkstra() {
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
	for (int i=1;i<=n;i++) {
		vis[i]=0;
		if (dis[i]<inf) {
			q.push({dis[i],i});
		}
	}
	while (!q.empty()) {
		int now=q.top().second; q.pop();
		if (vis[now]) {
			continue;
		}
		vis[now]=1;
		for (auto [to,w]:e[now]) {
			if (dis[to]>dis[now]+w) {
				dis[to]=dis[now]+w;
				q.push({dis[to],to});
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0,inf=dis[0];
	dijkstra();
	for (int t=1;t<=k;t++) {
		int top=0;
		for (int i=1;i<=n;i++) {
			if (dis[i]==inf) {
				continue;
			}
			point now=(point){i,dis[i]+1LL*i*i};
			while (top>1&&(st[top]-st[top-1])*(now-st[top])<=0) {
				top--;
			}
			st[++top]=now;
		}
		for (int i=1,j=1;i<=n;i++) {
			point now=(point){-2LL*i,1LL*i*i};
			while (j<top&&calc(now,st[j])>calc(now,st[j+1])) {
				j++;
			}
			dis[i]=min(dis[i],calc(now,st[j]));
		}
		dijkstra();
	}
	for (int i=1;i<=n;i++) {
		cout<<dis[i]<<" \n"[i==n];
	}
	
	return 0;
}