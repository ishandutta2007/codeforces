#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=1300;
const int inf=1e9;
int head[N],vis[N],pre[N],s,t,flow[N],cnt;
ll cost,dis[N];
struct edge{
	int u,c,d,nxt;
}e[N*N];
void addedge(int u,int v,int c,int d){
	e[cnt]=(edge){v,c,d,head[u]},head[u]=cnt++;
	e[cnt]=(edge){u,0,-d,head[v]},head[v]=cnt++;
}
bool bfs(){
	queue<int> q;q.push(s);
	rep(i,0,t+1)dis[i]=inf,vis[i]=0;
	vis[s]=1;dis[s]=0;flow[s]=inf;
	while(!q.empty()){
		int u=q.front();
		q.pop();vis[u]=0;
		for(int i=head[u];~i;i=e[i].nxt){
			int w=e[i].u,d=e[i].d;
			if(e[i].c>0&&dis[w]>dis[u]+d){
				dis[w]=dis[u]+d;
				pre[w]=i;
				flow[w]=min(flow[u],e[i].c);
				if(!vis[w]){
					vis[w]=1;
					q.push(w);
				}
			}
		}
	}
	return dis[t]!=inf;
}
void costflow(){
	pre[s]=-1;
	while(bfs()){
		for(int i=pre[t];~i;i=pre[e[i^1].u]){
			e[i].c-=flow[t];e[i^1].c+=flow[t];
		}
		cost+=dis[t]*flow[t];
	}
}
int a[51][51],pos[51][51];
int main(){
	memset(head,-1,sizeof head);
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)rep(j,1,i)a[i][j]=a[j][i]=2;
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		a[u][v]=1,a[v][u]=0;
	}
	s=0;
	int tot=n;
	rep(i,1,n+1){
		rep(j,1,i){
			++tot;
			addedge(s,tot,1,0);
			if(a[i][j]!=1)addedge(tot,j,1,0),pos[j][i]=cnt-1;
			if(a[i][j]!=0)addedge(tot,i,1,0),pos[i][j]=cnt-1;
		}
	}
	t=tot+1;
	rep(i,1,n+1){
		rep(j,1,n+1)addedge(i,t,1,j);
	}
	costflow();
	rep(i,1,n+1){
		rep(j,1,n+1){
			if(a[i][j]<2)printf("%d",a[i][j]);
			else printf("%d",e[pos[i][j]].c);
		}
		printf("\n");
	}
}