#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 200005
#define MM 400005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<pli,int> plii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,k;
int sz[MN],d[MN];
vector<pii>G[MN];
priority_queue<plii>pq;
map<int,bool>vis[MN];
map<int,ll>dis[MN];
int main(){
	int x,y,z;
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,m)scanf("%d%d%d",&x,&y,&z),G[x].pb(mp(z,y)),G[y].pb(mp(z,x));
	F(i,1,n)sort(G[i].begin(),G[i].end()),sz[i]=min((int)G[i].size(),k);
	F(i,1,n)dis[i][i]=0ll,pq.push(mp(mp(0ll,i),i));
	k=k*2+n;
	while(!pq.empty()){
		plii p=pq.top();pq.pop();
		ll d=-p.fi.fi;int u=p.fi.se,o=p.se;
//		printf("%d->%d:%lld\n",o,u,d);
		if(vis[o][u])continue;
		vis[o][u]=1;
		F2(i,0,sz[u]){
			if(!dis[o].count(G[u][i].se)||dis[o][G[u][i].se]>d+G[u][i].fi){
				ll nd=dis[o][G[u][i].se]=d+G[u][i].fi;
				pq.push(mp(mp(-nd,G[u][i].se),o));
			}
		}
		if(!--k)return printf("%lld\n",d),0;
	}
	return 0;
}