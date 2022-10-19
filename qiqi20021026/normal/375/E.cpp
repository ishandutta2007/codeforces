#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define N 505
#define INF 0x3f3f
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

int n,m,s,x,y,z,tot,dist[N][N],g[N][N],head[N],size[N],c[N];
short f[N][N][N];
struct edge{int v,nxt;}e[N*2];

void add(int x,int y){e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;}

void dfs(int u,int fa){
	for (int i=head[u];i;i=e[i].nxt) if (e[i].v!=fa) dfs(e[i].v,u);
	for (int i=1;i<=n;i++)
		if (dist[u][i]<=m){
			size[u]=1; f[u][i][1]=!c[i];
			for (int j=head[u],v;j;j=e[j].nxt)
				if ((v=e[j].v)!=fa){
					for (int k=min(size[u]+size[v],s);k>=0;k--){
						int tmp=INF; 
						for (int l=max(k-size[u],0);l<=min(k,size[v]);l++) tmp=min(tmp,f[u][i][k-l]+g[v][l]);
						for (int l=max(k-size[u]+1,1);l<=min(k,size[v]);l++) tmp=min(tmp,f[u][i][k-l+1]+f[v][i][l]-(!c[i]));
						f[u][i][k]=tmp;
					}
					size[u]+=size[v];
				}
		}
	for (int i=1;i<=min(s,size[u]);i++)
		for (int j=1;j<=n;j++)
			g[u][i]=min(g[u][i],f[u][j][i]);
}
			
int main(){
	memset(dist,INF,sizeof dist); memset(f,INF,sizeof f); memset(g,INF,sizeof g);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){scanf("%d",&c[i]); s+=c[i];}
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y); add(y,x);
		dist[x][y]=dist[y][x]=z;
	}
	
	for (int i=1;i<=n;i++) dist[i][i]=0;
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	dfs(1,0);
	if (g[1][s]>=INF) puts("-1"); else printf("%d\n",g[1][s]);
	
	return 0;
}