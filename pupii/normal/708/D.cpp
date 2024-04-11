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
int fir[110],dis[1010],nxt[1010],w[1010],cost[1010],id=1,S,T;
il vd link(int a,int b,int c,int d){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c,cost[id]=d;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=0,cost[id]=-d;
}
il bool Mincost(ll&totalcost){
	static int que[110],hd,tl,lst[110];
	static ll dist[110];
	static bool inq[110];
	hd=tl=0;que[tl++]=S;inq[S]=1;
	for(int i=1;i<=T;++i)dist[i]=1e9;
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
		if(hd==110)hd=0;
	}
	if(dist[T]>0)return 0;
	int flow=1e9;
	for(int i=lst[T];i;i=lst[dis[i^1]])flow=std::min(flow,w[i]);
	for(int i=lst[T];i;i=lst[dis[i^1]])totalcost+=1ll*flow*cost[i],w[i]-=flow,w[i^1]+=flow;
	return 1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("708d.in","r",stdin);
	freopen("708d.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b,c,f;S=n+1,T=n+2;
	ll ans=0;
	while(m--){
		a=gi(),b=gi(),c=gi(),f=gi();
		link(S,b,f,-100000000),link(a,T,f,-100000000);
		ans+=f*200000000ll;
		if(f<=c)link(a,b,c-f,1),link(a,b,1e9,2),link(b,a,f,1);
		else ans+=f-c,link(a,b,1e9,2),link(b,a,f-c,0),link(b,a,c,1);
	}
	link(n,1,1e9,0);
	while(Mincost(ans));printf("%lld\n",ans);
	return 0;
}