#include<bits/stdc++.h>

using namespace std;

int n,m,S,T,x,y,ans,d1[1200],d2[1200],q[1200];
bool g[1200][1200];

int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		g[x][y]=g[y][x]=1;
	}
	memset(d1,-1,sizeof d1); d1[S]=0;
	int tt=0,ww=1; q[1]=S;
	while (tt<ww){
		int u=q[++tt];
		for (int v=1;v<=n;++v)
			if (g[u][v]&&d1[v]==-1){
				d1[v]=d1[u]+1;
				q[++ww]=v;
			}
	}
	int dist=d1[T];
	memset(d2,-1,sizeof d2); d2[T]=0;
	tt=0,ww=1; q[1]=T;
	while (tt<ww){
		int u=q[++tt];
		for (int v=1;v<=n;++v)
			if (g[u][v]&&d2[v]==-1){
				d2[v]=d2[u]+1;
				q[++ww]=v;
			}
	}
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
			if (!g[i][j])
				if (d1[i]+d2[j]+1>=dist&&d1[j]+d2[i]+1>=dist) ++ans;
	printf("%d\n",ans);
	
	return 0;
}