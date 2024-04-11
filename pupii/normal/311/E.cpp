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
int s[12010],V[12010],fir[12010],dis[1000010],nxt[1000010],w[1000010],id=1,S,T,cnt;
il vd link(int a,int b,int c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=0;
}
int dep[12010],head[12010];
il bool BFS(){
    static int que[12010],hd,tl;
    memset(dep,0,sizeof dep);
    hd=tl=0;que[tl++]=S,dep[S]=1;
    while(hd^tl){
        int x=que[hd++];
        for(int i=fir[x];i;i=nxt[i])
            if(w[i]&&!dep[dis[i]])
                dep[dis[i]]=dep[x]+1,que[tl++]=dis[i];
    }
    return dep[T];
}
il int Dinic(int x,int maxflow){
    if(T==x)return maxflow;
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
	int n=gi(),m=gi(),g=gi(),ans=0;cnt=n,S=++cnt,T=++cnt;
	for(int i=1;i<=n;++i)s[i]=gi();
	for(int i=1;i<=n;++i){
		V[i]=gi();
		if(s[i])link(S,i,V[i]);
		else link(i,T,V[i]);
	}
	for(int i=1;i<=m;++i){
		int vi=gi(),wi=gi(),ki=gi();ans+=wi;
		++cnt;
		while(ki--){
			if(vi)link(cnt,gi(),1e9);
			else link(gi(),cnt,1e9);
		}
		int yi=gi();
		if(yi)wi+=g;
		if(vi)link(S,cnt,wi);
		else link(cnt,T,wi);
	}
	while(BFS())memcpy(head,fir,sizeof head),ans-=Dinic(S,1e9);
	printf("%d\n",ans);
	return 0;
}