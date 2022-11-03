#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int x[200010],y[200010],cx[200010],cy[200010],numx[200010],numy[200010],cnt;
int S,T,SS,TT,fir[400010],dis[10000010],nxt[10000010],w[10000010],id=1;
void link(int a,int b,int c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=0;
}
void Link(int a,int b,int c,int d){
	if(c)link(a,T,c),link(S,b,c);
	if(d-c)link(a,b,d-c);
}
int dep[400010],head[400010];
bool BFS(){
	static int que[400010],hd,tl;
	hd=tl=0;que[tl++]=S;
	memset(dep,0,sizeof dep);dep[S]=1;
	while(hd^tl){
		int x=que[hd++];
		for(int i=fir[x];i;i=nxt[i])
			if(!dep[dis[i]]&&w[i])
				dep[dis[i]]=dep[x]+1,que[tl++]=dis[i];
	}
	return dep[T];
}
int Dinic(int x,int maxflow){
	if(x==T)return maxflow;
	int ret=0;
	for(int&i=head[x];i;i=nxt[i])
		if(dep[dis[i]]==dep[x]+1&&w[i]){
			int d=Dinic(dis[i],std::min(maxflow-ret,w[i]));
			w[i]-=d,w[i^1]+=d,ret+=d;
			if(ret==maxflow)break;
		}
	return ret;
}
int Edge[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),N=200000;
	for(int i=1;i<=n;++i)++cx[x[i]=gi()],++cy[y[i]=gi()];
	S=++cnt,T=++cnt,SS=++cnt,TT=++cnt;
	for(int i=1;i<=N;++i){
		if(cx[i]>1)numx[i]=++cnt,Link(SS,numx[i],cx[i]>>1,(cx[i]>>1)+(cx[i]&1));
		if(cy[i]>1)numy[i]=++cnt,Link(numy[i],TT,cy[i]>>1,(cy[i]>>1)+(cy[i]&1));
	}
	for(int i=1;i<=n;++i){
		int L=numx[x[i]],R=numy[y[i]];
		if(!L)L=SS;
		if(!R)R=TT;
		Edge[i]=id+1;link(L,R,1);
	}
	link(TT,SS,1e9);
	while(BFS())memcpy(head,fir,sizeof fir),Dinic(S,1e9);
	for(int i=1;i<=n;++i)putchar(w[Edge[i]]?'r':'b');
	return 0;
}