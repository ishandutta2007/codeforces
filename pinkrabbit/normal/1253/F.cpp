#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 100005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,k,q;
int eu[MM],ev[MM],ew[MM],pp[MM];ll nw[MM];
int h[MN],nxt[MM],to[MM],w[MM],tot;
inline void ins(int x,int y,int z){nxt[++tot]=h[x];to[tot]=y;w[tot]=z;h[x]=tot;}
int bel[MN],vis[MN];ll dis[MN];
priority_queue<pli,vector<pli>,greater<pli>>pq;
int fa[MN];
int ff(int x){return fa[x]?fa[x]=ff(fa[x]):x;}
vector<pil>g[MN];
int dep[MN],faz[MN][17];ll mx[MN][17];
void dfs(int u,int fz){
	dep[u]=dep[fz]+1;
	for(auto e:g[u]){
		int v=e.fi;ll w=e.se;
		if(v==fz)continue;
		faz[v][0]=u,mx[v][0]=w;
		for(int j=0;j<16;++j){
			faz[v][j+1]=faz[faz[v][j]][j];
			if(!faz[v][j+1])break;
			mx[v][j+1]=max(mx[v][j],mx[faz[v][j]][j]);
		}
//		printf("%d->%d:%lld\n",u,v,w);
		dfs(v,u);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	F(i,1,m)scanf("%d%d%d",&eu[i],&ev[i],&ew[i]),ins(eu[i],ev[i],ew[i]),ins(ev[i],eu[i],ew[i]);
	F(i,k+1,n)dis[i]=infll;
	F(i,1,k)bel[i]=i,pq.push({0,i});
	while(!pq.empty()){
		pli p=pq.top();pq.pop();
		int u=p.se;ll d=p.fi;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i],z=w[i];
			if(dis[v]>d+z){
				dis[v]=d+z;
				bel[v]=bel[u];
				pq.push({dis[v],v});
			}
		}
	}
//	F(i,1,n)printf("%lld,",dis[i]);puts("");
//	F(i,1,n)printf("%d,",bel[i]);puts("");
	F(i,1,m)if(bel[eu[i]]!=bel[ev[i]])nw[i]=dis[eu[i]]+dis[ev[i]]+ew[i];
//	F(i,1,m)printf("%d-%d-%lld\n",eu[i],ev[i],nw[i]);
	F(i,1,m)pp[i]=i;
	sort(pp+1,pp+m+1,[](int i,int j){return nw[i]<nw[j];});
	F(id,1,m){
		int i=pp[id],u=eu[i],v=ev[i];ll w=nw[i];
		if(ff(u)!=ff(v)){
			fa[ff(u)]=ff(v);
//			printf("%d<->%d:%lld\n",u,v,w);
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
	}
	dfs(1,0);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=0;
		if(dep[x]<dep[y])swap(x,y);
		for(int d=dep[x]-dep[y],j=0;d;d>>=1,++j)
			if(d&1)ans=max(ans,mx[x][j]),x=faz[x][j];
//		printf("%d,%d\n",x,y);
		if(x==y){printf("%lld\n",ans);continue;}
		for(int j=16;j>=0;--j)
			if(faz[x][j]!=faz[y][j])
				ans=max(ans,max(mx[x][j],mx[y][j])),
				x=faz[x][j],y=faz[y][j];
		printf("%lld\n",max(ans,max(mx[x][0],mx[y][0])));
	}
	return 0;
}