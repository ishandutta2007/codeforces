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
int px[100010],py[100010],tot;
int S,T,S0,T0,fir[200010],dep[200010],head[200010],dis[10000010],nxt[10000010],w[10000010],id=1,cnt,nowS,nowT;
std::map<int,int>line,row;
int lim[200010],o[200010],siz[200010],Edge[100010];
il vd link(int a,int b,int c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=0;
}
il vd Link(int a,int b,int c,int d){
	if(c>d)puts("-1"),exit(0);
	if(c)link(a,T,c),link(S,b,c),tot+=c;
	if(d-c)link(a,b,d-c);
}
il bool BFS(){
	static int que[200010],hd,tl;
	memset(dep,0,sizeof dep);
	hd=tl=0;que[tl++]=nowS;dep[nowS]=1;
	while(hd^tl){
		int x=que[hd++];
		for(int i=fir[x];i;i=nxt[i])
			if(!dep[dis[i]]&&w[i])
				dep[dis[i]]=dep[x]+1,que[tl++]=dis[i];
	}
	return dep[nowT];
}
il int Dinic(int x,int maxflow){
	if(x==nowT)return maxflow;
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
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),r=gi(),b=gi(),flg=1;
	if(r<b)std::swap(r,b),flg=0;
	S=1,T=2,S0=3,T0=4,cnt=4;
	for(int i=1;i<=n;++i){
		px[i]=gi(),py[i]=gi();
		if(line.find(px[i])==line.end())line[px[i]]=++cnt,o[cnt]=1;
		if(row.find(py[i])==row.end())row[py[i]]=++cnt,o[cnt]=2;
		++siz[line[px[i]]],++siz[row[py[i]]];
	}
	for(int i=5;i<=cnt;++i)lim[i]=1e9;
	for(int i=1;i<=m;++i){
		int t=gi(),l=gi(),d=gi();
		if(t==1){if(line.find(l)!=line.end())lim[line[l]]=std::min(lim[line[l]],d);}
		else{if(row.find(l)!=row.end())lim[row[l]]=std::min(lim[row[l]],d);}
	}
	for(int i=5;i<=cnt;++i)
		if(o[i]==1)Link(S0,i,std::max(0,(siz[i]-lim[i]+1)/2),std::min(siz[i],(siz[i]+lim[i])/2));
		else Link(i,T0,std::max(0,(siz[i]-lim[i]+1)/2),std::min(siz[i],(siz[i]+lim[i])/2));
	link(T0,S0,1e9);
	for(int i=1;i<=n;++i)link(line[px[i]],row[py[i]],1),Edge[i]=id;
	int ans=0;
	nowS=S,nowT=T;while(BFS())memcpy(head,fir,sizeof fir),ans+=Dinic(nowS,1e9);
	if(ans!=tot)return puts("-1"),0;
	ans=0;
	nowS=S0,nowT=T0;while(BFS())memcpy(head,fir,sizeof fir),ans+=Dinic(nowS,1e9);
	printf("%lld\n",1ll*r*(n-ans)+1ll*b*ans);
	for(int i=1;i<=n;++i)
		if(w[Edge[i]]^flg)putchar('r');
		else putchar('b');
	return 0;
}