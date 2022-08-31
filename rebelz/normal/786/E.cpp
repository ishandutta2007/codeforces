#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int inf=1<<30;
int n,m,tot=0,src,sink,num=0;
int v[6000005],c[6000005],rev[6000005],nxt[6000005],h[1000005],level[1000005],q[1000005];
int f[20005][20],g[20005][20],dep[20005],cnt1[2000005],cnt2[2000005],pos[2000005];

void addedge(int x,int y,int z,int b){
	if(y==0)
		return;
	v[++tot]=y; c[tot]=z; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=b*z; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
}

bool bfs(){
	memset(level,-1,sizeof(level));
	int front=0,rear=0;
	level[src]=0,q[rear++]=src;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]){
			if(level[v[p]]<0&&c[p]>0){
				level[v[p]]=level[t]+1;
				q[rear++]=v[p];
			}
		}
		if(level[sink]>=0)
			return true;
	}
	return false;
}

int fun(int u,int low){
	if(u==sink)
		return low;
	int res=0;
	for(int p=h[u];p;p=nxt[p]){
		if(level[v[p]]==level[u]+1&&c[p]>0){
			int flow=fun(v[p],min(c[p],low));
			c[p]-=flow,c[rev[p]]+=flow,res+=flow,low-=flow;
			if(low<=0)
				break;
		}
	}
	if(res==0)
		level[u]=-1;
	return res;
}

int dinic(){
	int maxflow=0;
	while(bfs())
		maxflow+=fun(src,inf);
	return maxflow;
}

void dfs(int u,int fa){
	for(int i=1;i<=19;i++)
		f[u][i]=f[f[u][i-1]][i-1],g[u][i]=++num;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa)
			continue;
		f[v[p]][0]=u,g[v[p]][0]=++num,dep[v[p]]=dep[u]+1,pos[v[p]]=c[p];
		dfs(v[p],u);
	}
}

void link(int x,int y,int k){
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=19;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
			addedge(k,g[x][i],inf,0),x=f[x][i];
	if(x==y)
		return;
	for(int i=19;i>=0;i--)
		if(f[x][i]!=f[y][i])
			addedge(k,g[x][i],inf,0),addedge(k,g[y][i],inf,0),x=f[x][i],y=f[y][i];
	addedge(k,g[x][0],inf,0),addedge(k,g[y][0],inf,0);
}

int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y,i,1);
	}
	num=m,src=++num,sink=++num,g[1][0]=++num,dep[1]=1;
	dfs(1,-1);
	memset(h,0,sizeof(h));
	tot=0;
	for(int i=1;i<=n;i++)
		addedge(g[i][0],sink,1,0);
	for(int i=1;i<=19;i++)
		for(int j=1;j<=n;j++)
			addedge(g[j][i],g[j][i-1],inf,0),addedge(g[j][i],g[f[j][i-1]][i-1],inf,0);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		addedge(src,i,1,0); link(x,y,i);
	}
	printf("%d\n",dinic());
	bfs();
	for(int i=1;i<=m;i++)
		if(level[i]<0)
			cnt1[++cnt1[0]]=i;
	for(int i=2;i<=n;i++)
		if(level[g[i][0]]>=0)
			cnt2[++cnt2[0]]=pos[i];
	for(int i=0;i<=cnt1[0];i++)
		printf("%d ",cnt1[i]);
	printf("\n");
	for(int i=0;i<=cnt2[0];i++)
		printf("%d ",cnt2[i]);
	printf("\n");
	return 0;
}