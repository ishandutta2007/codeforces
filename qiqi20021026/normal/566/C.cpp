#include<bits/stdc++.h>

using namespace std;

#define N 800000
#define INF 0x3f3f3f3f

int n,x,y,z,rt,ansid,w[N],head[N],tot,sz[N],mx[N];
double ans,der[N];
bool vis[N];
struct edge{int v,l,nxt;}e[N];

void add(int x,int y,int z){
	e[++tot].v=y; e[tot].l=z; e[tot].nxt=head[x]; head[x]=tot;
}

void dfs(int u,int fa,int l,int o){
	der[o]+=1.5*w[u]*sqrt(1.0*l);
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa) dfs(v,u,l+e[i].l,o);
}

double calc(int u,int fa,int l){
	double ret=w[u]*sqrt(1.0*l*l*l);
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa) ret+=calc(v,u,l+e[i].l);
	return ret;
}

void getsz(int u,int fa){
	sz[u]=1;
	for (int i=head[u],v;i;i=e[i].nxt)
		if (!vis[v=e[i].v]&&v!=fa){getsz(v,u); sz[u]+=sz[v];}
}

void getrt(int u,int fa,int num){
	mx[u]=num-sz[u];
	for (int i=head[u],v;i;i=e[i].nxt)
		if (!vis[v=e[i].v]&&v!=fa){getrt(v,u,num); mx[u]=max(mx[u],sz[v]);}
	rt=mx[u]<mx[rt]?u:rt;
}

void solve(int u){
	vis[u]=1;
	double tmp=calc(u,0,0),sum=0;
	if (tmp<ans){ans=tmp; ansid=u;}
	for (int i=head[u],v;i;i=e[i].nxt){
		der[v=e[i].v]=0; dfs(v,u,e[i].l,v); sum+=der[v];
	}
	for (int i=head[u],v;i;i=e[i].nxt)
		if (!vis[v=e[i].v]&&der[v]-(sum-der[v])>0){
			getsz(v,0); mx[rt=0]=INF; getrt(v,0,sz[v]); solve(rt);
		}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&w[i]);
	for (int i=1;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,z);
	}
	ans=1e100; getsz(1,0); mx[rt=0]=INF; getrt(1,0,n); solve(rt);
	printf("%d %.8lf\n",ansid,ans);
	
	return 0;
}