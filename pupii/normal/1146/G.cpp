//yybakioi
#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
const int maxn=3000,maxm=2e7;
int S,T,fir[maxn],head[maxn],dis[maxm],nxt[maxm],w[maxm],id=1,dep[maxn];
il vd link(int a,int b,int c){
	//printf("%d %d %d\n",a,b,c);
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=0;
}
int num[51][51],cnt,qs[51];
il bool BFS(){
	static int que[maxn],hd,tl;
	hd=tl=0;
	que[tl++]=S;
	for(int i=1;i<=cnt;++i)dep[i]=0;dep[S]=1;
	while(hd^tl){
		int x=que[hd];
		for(int i=fir[x];i;i=nxt[i]){
			if(!dep[dis[i]]&&w[i]){
				dep[dis[i]]=dep[x]+1;
				que[tl++]=dis[i];
			}
		}
		++hd;
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
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	int n=gi(),h=gi(),m=gi();
	S=++cnt,T=++cnt;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=h;++j)
			num[i][j]=++cnt;
	for(int i=1;i<=m;++i)qs[i]=++cnt;
	for(int i=1;i<=n;++i){
		int lst=S;
		for(int j=0;j<=h;++j)link(lst,num[i][j],10000-j*j),lst=num[i][j];
		link(lst,T,1e9);
	}
	ll ans=n*10000;
	for(int i=1;i<=m;++i){
		int l=gi(),r=gi(),x=gi(),c=gi();
		link(qs[i],T,c);
		for(int j=l;j<=r;++j)link(num[j][x],qs[i],1e9);
	}
	while(BFS())
		memcpy(head,fir,sizeof head),
		ans-=Dinic(S,1e9);
	printf("%lld\n",ans);
	return 0;
}