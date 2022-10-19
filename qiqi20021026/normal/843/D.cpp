#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 120000
#define P(x,y) make_pair(x,y)
#define INF 0x3f3f3f3f3f3f3f3fLL

LL n,m,p,x,y,z,c,op,tot,head[N],dist[N],dist2[N];
bool vis[N];
vector<LL> vec[N];
struct edge{LL v,l,nxt;}e[N];
priority_queue<pair<LL,LL> ,vector<pair<LL,LL> >,greater<pair<LL,LL> > > pq;

void add(LL x,LL y,LL z){e[++tot].v=y; e[tot].l=z; e[tot].nxt=head[x]; head[x]=tot;}

int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	for (LL i=1;i<=m;++i){
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
	}
	memset(dist,0x3f,sizeof dist); dist[1]=0;
	memset(vis,0,sizeof vis);
	pq.push(P(0,1));
	while (!pq.empty()){
		LL x=pq.top().second; pq.pop();
		if (vis[x]) continue; vis[x]=1;
		for (LL i=head[x];i;i=e[i].nxt)
			if (!vis[e[i].v]&&dist[e[i].v]>dist[x]+e[i].l){
				dist[e[i].v]=dist[x]+e[i].l;
				pq.push(P(dist[e[i].v],e[i].v));
			}
	}
	for (LL i=1;i<=n;++i)
		for (LL j=head[i];j;j=e[j].nxt)
			e[j].l=dist[i]+e[j].l-dist[e[j].v];
	while (p--){
		scanf("%lld",&op);
		if (op==1){
			scanf("%lld",&x);
			printf("%lld\n",dist[x]>=INF?-1:dist[x]);
		}
		else{
			scanf("%lld",&c);
			for (LL i=1;i<=c;++i){scanf("%lld",&x); ++e[x].l;}
			memset(dist2,0x3f,sizeof dist2); dist2[1]=0;
			memset(vis,0,sizeof vis);
			for (LL i=0;i<=c;++i) vec[i].clear();
			vec[0].push_back(1);
			for (LL i=0;i<=c;){
				if (!vec[i].size()){++i; continue;}
				LL j=vec[i].size()-1; x=vec[i][j];
				vec[i].erase(--vec[i].end());
				if (vis[x]) continue; vis[x]=1;
				for (LL j=head[x];j;j=e[j].nxt)
					if (!vis[e[j].v]&&dist2[e[j].v]>dist2[x]+e[j].l){
						dist2[e[j].v]=dist2[x]+e[j].l;
						if (dist2[e[j].v]<=c) vec[dist2[e[j].v]].push_back(e[j].v);
					}
			}
			for (LL i=1;i<=n;++i){dist[i]+=dist2[i]; dist[i]=min(dist[i],INF);}
			for (LL i=1;i<=n;++i)
				for (LL j=head[i];j;j=e[j].nxt)
					e[j].l=dist2[i]+e[j].l-dist2[e[j].v];
		}
	}
	
	return 0;
}