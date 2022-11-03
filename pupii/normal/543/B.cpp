// luogu-judger-enable-o2
// luogu-judger-enable-o2
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
int n,m,fir[3010],dis[6010],nxt[6010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int D[3010][3010];
int que[3010],hd,tl;
il vd BFS(int x,int*d){
	hd=tl=0;que[tl++]=x;
	for(int i=1;i<=n;++i)d[i]=-1;
	d[x]=0;
	while(hd^tl){
		int x=que[hd++];
		for(int i=fir[x];i;i=nxt[i])
			if(d[dis[i]]==-1)d[dis[i]]=d[x]+1,que[tl++]=dis[i];
	}
}
int main(){
	n=gi(),m=gi();
	int u,v;
	for(int i=1;i<=m;++i)u=gi(),v=gi(),link(u,v),link(v,u);
	int s1=gi(),t1=gi(),l1=gi();
	int s2=gi(),t2=gi(),l2=gi();
	for(int i=1;i<=n;++i)BFS(i,D[i]);
	int ans=1e9;
	auto upd=[&](int a,int b,int c=0){if(a<=l1&&b<=l2&&a+b-c<ans)ans=a+b-c;};
	upd(D[s1][t1],D[s2][t2]);
	for(int u=1;u<=n;++u)
		for(int v=1;v<=n;++v){
			upd(D[s1][u]+D[u][v]+D[v][t1],D[s2][u]+D[u][v]+D[v][t2],D[u][v]);
			upd(D[s1][u]+D[u][v]+D[v][t1],D[s2][v]+D[u][v]+D[u][t2],D[u][v]);
		}
	if(ans<1e9)printf("%d\n",m-ans);
	else puts("-1");
	return 0;
}