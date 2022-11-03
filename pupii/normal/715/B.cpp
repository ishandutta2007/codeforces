#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,m,L,s,t,fir[1010],dis[20010],nxt[20010],w[20010],id=1;
il vd link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
ll distt[1010],dist[1010];
std::priority_queue<std::pair<int,int>>que;
il int getw(int w){return w?w:1;}
bool vis[1010];
il vd Dijkstra(){
	memset(distt,63,sizeof distt);
	memset(vis,0,sizeof vis);
	distt[t]=0;que.push({-distt[t],t});
	while(!que.empty()){
		int x=que.top().second;que.pop();
		if(vis[x])continue;vis[x]=1;
		for(int i=fir[x];i;i=nxt[i])
			if(distt[dis[i]]>distt[x]+getw(w[i])){
				distt[dis[i]]=distt[x]+getw(w[i]);
				que.push({-distt[dis[i]],dis[i]});
			}
	}
}
il vd Dijkstras(){
	memset(dist,63,sizeof dist);
	memset(vis,0,sizeof vis);
	dist[s]=0;que.push({-dist[s],s});
	while(!que.empty()){
		int x=que.top().second;que.pop();
		if(vis[x])continue;vis[x]=1;
		for(int i=fir[x];i;i=nxt[i]){
			if(vis[dis[i]])continue;
			if(!w[i])w[i]=std::max(1ll,L-dist[x]-distt[dis[i]]);
			if(dist[dis[i]]>dist[x]+w[i]){
				dist[dis[i]]=dist[x]+w[i];
				que.push({-dist[dis[i]],dis[i]});
			}
		}
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi(),L=gi(),s=gi()+1,t=gi()+1;
	int u,v,qvq;
	while(m--)u=gi()+1,v=gi()+1,qvq=gi(),link(u,v,qvq),link(v,u,qvq);
	Dijkstra();
	Dijkstras();
	if(dist[t]==L){
		puts("YES");
		for(int i=2;i<=id;i+=2)printf("%d %d %d\n",dis[i]-1,dis[i^1]-1,w[i]|w[i^1]);
	}else puts("NO");
	return 0;
}