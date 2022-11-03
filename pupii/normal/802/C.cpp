#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int fir[170],dis[100010],nxt[100010],w[100010],id=1,S,T;
ll cost[100010];
il vd link(int a,int b,int c,ll d){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c,cost[id]=d;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=0,cost[id]=-d;
}
il vd Mincost(ll&totalcost){
	static int que[170],hd,tl,lst[170];
	static ll dist[170];
	static bool inq[170];
	hd=tl=0;que[tl++]=S;inq[S]=1;
	for(int i=1;i<=T;++i)dist[i]=1e18;
	dist[S]=0;
	while(hd^tl){
		int x=que[hd];
		for(int i=fir[x];i;i=nxt[i])
			if(w[i]&&dist[dis[i]]>dist[x]+cost[i]){
				dist[dis[i]]=dist[x]+cost[i],lst[dis[i]]=i;
				if(!inq[dis[i]]){
					inq[dis[i]]=1,que[tl++]=dis[i];
					if(tl==110)tl=0;
				}
			}
		inq[x]=0,++hd;
		if(hd==170)hd=0;
	}
	if(dist[T]>0)return;
	for(int i=lst[T];i;i=lst[dis[i^1]])totalcost+=cost[i],--w[i],++w[i^1];
}
int a[81],c[81];
int main(){
#ifndef ONLINE_JUDGE
	freopen("802c.in","r",stdin);
	freopen("802c.out","w",stdout);
#endif
	int n=gi(),k=gi();S=n+n+1,T=n+n+2;
	for(int i=1;i<=n;++i)a[i]=gi();
	for(int i=1;i<=n;++i)c[i]=gi();
	for(int i=1;i<=n;++i)link(S,i,1,c[a[i]]),link(i,i+n,1,-1e9),link(i+n,T,1,0);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			link(i+n,j,1,a[i]==a[j]?0:c[a[j]]);
	ll ans=1e9*n;
	if(k>n)k=n;while(k--)Mincost(ans);
	printf("%lld\n",ans);
	return 0;
}