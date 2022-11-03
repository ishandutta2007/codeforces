// SYZ NIUBI
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
int n,m,a,b,d,block[71],k,blocknum[71],siz[71],realblock[71];
int fir[71],dis[410],nxt[410],w[410],id;
il vd link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
il vd dfs(int x,int orz){
	realblock[x]=orz,++siz[orz];
	for(int i=fir[x];i;i=nxt[i])if(w[i]==a&&!realblock[dis[i]])dfs(dis[i],orz);
}
ll dist[1<<17][71],ans[71];bool vis[1<<17][71];
std::priority_queue<std::pair<ll,std::pair<int,int>>>que;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi(),a=gi(),b=gi();
	int u,v,c;
	while(m--)u=gi(),v=gi(),c=gi(),link(u,v,c),link(v,u,c);
	for(int i=1;i<=n;++i)if(!realblock[i])dfs(i,++k);
	for(int i=1;i<=k;++i)if(siz[i]>3)blocknum[i]=d++;else blocknum[i]=-1;
	for(int i=1;i<=n;++i)block[i]=blocknum[realblock[i]];
	memset(dist,63,sizeof dist);memset(ans,63,sizeof ans);
	dist[~block[1]?1<<block[1]:0][1]=0;que.push({0,{~block[1]?1<<block[1]:0,1}});
	while(!que.empty()){
		int x=que.top().second.first,y=que.top().second.second;que.pop();
		if(vis[x][y])continue;vis[x][y]=1;
		if(ans[y]==ans[0])ans[y]=dist[x][y];
		for(int i=fir[y];i;i=nxt[i]){
			int tx=x,ty=dis[i];
			if(~block[ty])tx|=1<<block[ty];
			if(dist[tx][ty]<=dist[x][y]+w[i])continue;
			if(w[i]==b&&((~block[ty]&&tx==x)||(realblock[ty]==realblock[y])))continue;
			dist[tx][ty]=dist[x][y]+w[i];
			que.push({-dist[tx][ty],{tx,ty}});
		}
	}
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}