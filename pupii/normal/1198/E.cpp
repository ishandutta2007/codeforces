#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int S,T,fir[210],dep[210],head[210],dis[10000010],nxt[10000010],w[10000010],id=1,cnt;
il vd link(int a,int b,int c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=0;
}
il bool BFS(){
	static int que[210],hd,tl;
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
il int Dinic(int x,int maxflow){
	if(x==T)return maxflow;
	int ret=0;
	for(int&i=head[x];i;i=nxt[i])
		if(w[i]&&dep[dis[i]]==dep[x]+1){
			int d=Dinic(dis[i],std::min(maxflow-ret,w[i]));
			w[i]-=d,w[i^1]+=d,ret+=d;
			if(ret==maxflow)break;
		}
	return ret;
}
int xl[51],xr[51],yl[51],yr[51],ux[101],uy[101],mx,my;
std::set<std::pair<int,int>>itst;
signed main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=m;++i){
		xl[i]=gi(),yl[i]=gi();
		xr[i]=gi(),yr[i]=gi();
		ux[++mx]=xl[i];ux[++mx]=xr[i]+1;
		uy[++my]=yl[i];uy[++my]=yr[i]+1;
	}
	std::sort(ux+1,ux+mx+1);mx=std::unique(ux+1,ux+mx+1)-ux-1;
	std::sort(uy+1,uy+my+1);my=std::unique(uy+1,uy+my+1)-uy-1;
    S=mx+my+1,T=cnt=mx+my+2;
	for(int i=1;i<mx;++i)link(S,i,ux[i+1]-ux[i]);
	for(int i=1;i<my;++i)link(i+mx,T,uy[i+1]-uy[i]);
	for(int i=1;i<=m;++i){
		xl[i]=std::lower_bound(ux+1,ux+mx+1,xl[i])-ux;
		xr[i]=std::lower_bound(ux+1,ux+mx+1,xr[i]+1)-ux;
		yl[i]=std::lower_bound(uy+1,uy+my+1,yl[i])-uy;
		yr[i]=std::lower_bound(uy+1,uy+my+1,yr[i]+1)-uy;
		for(int j=xl[i];j<xr[i];++j)
			for(int k=yl[i];k<yr[i];++k)
				link(j,k+mx,1e18);
	}
	int ans=0;while(BFS())memcpy(head,fir,sizeof fir),ans+=Dinic(S,1e18);
	printf("%lld\n",ans);
	return 0;
}