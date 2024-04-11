#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=50050;
int n,k,el,head[maxn],to[maxn*2],nxt[maxn*2];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
int rt,tot,sz[maxn],son[maxn];
bool vis[maxn];
void getrt(int u,int f){
	son[u]=0;sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f || vis[v]) continue;
		getrt(v,u);
		sz[u]+=sz[v];son[u]=max(son[u],sz[v]);
	}
	son[u]=max(son[u],tot-sz[u]);
	if(son[u]<son[rt]) rt=u;
}
int dis[maxn],dl;
void getdis(int u,int f,int d){
	dis[++dl]=d;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f || vis[v]) continue;
		getdis(v,u,d+1);
	}
}
int binary1(int l,int x){
	int ans=0,r=dl;
	while(l<=r){
		int mid=(l+r)>>1;
		if(dis[mid]<x) l=mid+1;
		else r=(ans=mid)-1;
	}
	return ans;
}
int binary2(int l,int x){
	int ans=0,r=dl;
	while(l<=r){
		int mid=(l+r)>>1;
		if(dis[mid]<=x) l=(ans=mid)+1;
		else r=mid-1;
	}
	return ans;
}
ll getans(int u,int d){
	dl=0;ll ans=0;
	getdis(u,0,d);
	sort(dis+1,dis+dl+1);
	for(int l=1;l<dl;l++){
		if(dis[l]+dis[dl]<k) continue;
		if(dis[l]*2>k) break;
		int r1=binary1(l+1,k-dis[l]),r2=binary2(l+1,k-dis[l]);
		if(r1<=r2) ans+=r2-r1+1;
	}
	return ans;
}
ll ans;
void getall(int u){
	vis[u]=true;ans+=getans(u,0);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]) continue;
		ans-=getans(v,1);
		tot=sz[v];rt=0;getrt(v,u);
		getall(rt);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	son[0]=n+1;
	tot=n;getrt(1,0);
	getall(rt);
	printf("%lld\n",ans);
}