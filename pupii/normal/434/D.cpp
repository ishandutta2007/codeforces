#include<bits/stdc++.h>
#define il inline//
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
int a[51],b[51],c[51],l[51],r[51];
int num[51][202],cnt,S,T;
int fir[11000],head[10010],dep[10010],dis[10000010],nxt[10000010],id=1;
ll w[10000010];
il vd link(int a,int b,ll c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=0;
}
il bool BFS(){
	static int que[11000],hd,tl;
	memset(dep,0,sizeof dep);
	hd=tl=0;que[tl++]=S;dep[S]=1;
	while(hd^tl){
		int x=que[hd++];
		for(int i=fir[x];i;i=nxt[i])
			if(!dep[dis[i]]&&w[i])
				dep[dis[i]]=dep[x]+1,que[tl++]=dis[i];
	}
	return dep[T];
}
il ll Dinic(int x,ll maxflow){
	if(x==T)return maxflow;
	ll ret=0;
	for(int&i=head[x];i;i=nxt[i])
		if(w[i]&&dep[dis[i]]==dep[x]+1){
			ll d=Dinic(dis[i],std::min(maxflow-ret,w[i]));
			w[i]-=d,w[i^1]+=d,ret+=d;
			if(ret==maxflow)break;
		}
	 return ret;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("434d.in","r",stdin);
	freopen("434d.out","w",stdout);
#endif
	int n=gi(),m=gi();S=++cnt,T=++cnt;
	for(int i=1;i<=n;++i)a[i]=gi(),b[i]=gi(),c[i]=gi();
	for(int i=1;i<=n;++i)l[i]=gi(),r[i]=gi();
	for(int i=1;i<=n;++i){
		for(int j=l[i];j<=r[i]+1;++j)num[i][j+100]=++cnt;
		link(S,num[i][l[i]+100],1e18);
		for(int j=l[i];j<=r[i];++j)link(num[i][j+100],num[i][j+101],(1<<25)-(a[i]*j*j+b[i]*j+c[i]));
		link(num[i][r[i]+101],T,1e18);
	}
	int u,v,d;
	while(m--){
		u=gi(),v=gi(),d=gi();
		for(int i=std::max(l[u]-d,l[v])+100;i<=std::min(r[u]-d,r[v])+101;++i)link(num[u][i+d],num[v][i],1e18);
	}
	ll ans=(1ll<<25)*n;
	while(BFS())memcpy(head,fir,sizeof head),ans-=Dinic(S,1e18);
	printf("%lld\n",ans);
	return 0;
}