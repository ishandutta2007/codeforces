#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[100010];
int c[60];
int fir[121],dis[133],nxt[133],id=1,del,dist[133],que[133],hd,tl;
il vd bfs(int S,int T){
	memset(dist,-1,sizeof dist);
	hd=tl=0;que[tl++]=S;dist[S]=0;
	while(hd^tl){
		int x=que[hd++];
		for(int i=fir[x];i;i=nxt[i])
			if(i!=del&&dist[dis[i]]==-1){
				dist[dis[i]]=dist[x]+1;
				que[tl++]=dis[i];
			}
	}
	if(dist[T]==-1)dist[T]=1e9;
}
il vd link(int a,int b){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i){
		a[i]=gi();if(!a[i])--i,--n;
		else for(int j=59;~j;--j)if((a[i]>>j)&1)++c[j];
	}
	for(int i=0;i<60;++i)if(c[i]>=3)return puts("3"),0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(a[i]&a[j])link(i,j);
	int ans=1e9;
	for(int i=2;i<=id;i+=2)del=i,bfs(dis[i^1],dis[i]),ans=std::min(ans,dist[dis[i]]+1);
	printf("%d\n",ans>n?-1:ans);
	return 0;
}