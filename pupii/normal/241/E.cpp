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
int n,m,fir[1010],dis[10010],nxt[10010],w[10010],id;
il vd link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
int A[5010],B[5010],que[1010],dist[1010],inq[1010],ans[5010],cnt[1010];
bool yes1[1010],yesn[1010],yes[1010];
il vd dfs(int x,int p,bool*yes){
	yes[x]=1;
	for(int i=fir[x];i;i=nxt[i])if(w[i]==p&&!yes[dis[i]])dfs(dis[i],p,yes);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi();
	int a,b;
	for(int i=1;i<=m;++i)A[i]=a=gi(),B[i]=b=gi(),link(a,b,2),link(b,a,-1);
	dfs(1,2,yes1);dfs(n,-1,yesn);
	for(int i=1;i<=n;++i)yes[i]=yes1[i]&yesn[i];
	int hd=0,tl=0;
	memset(dist,63,sizeof dist);
	dist[1]=0;que[tl++]=1;
	while(hd^tl){
		int x=que[hd];
		if(++cnt[x]==n+1)return puts("No"),0;
		for(int i=fir[x];i;i=nxt[i])
			if(yes[dis[i]]&&dist[dis[i]]>dist[x]+w[i]){
				dist[dis[i]]=dist[x]+w[i];
				if(!inq[dis[i]]){
					inq[dis[i]]=1;que[tl]=dis[i];
					if(++tl==1010)tl=0;
				}
			}
		inq[x]=0;if(++hd==1010)hd=0;
	}
	for(int i=1;i<=m;++i){
		if(!yes[A[i]]||!yes[B[i]])ans[i]=1;
		else if(dist[B[i]]-dist[A[i]]==1)ans[i]=1;
		else if(dist[B[i]]-dist[A[i]]==2)ans[i]=2;
		else return puts("No"),0;
	}
	puts("Yes");
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}