#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=100005;
const int inf=111111111;
int n,m,s,a[maxn],p[maxn],g[maxn],c[505],f[505][505];
int find(int x){return x==g[x]?x:g[x]=find(g[x]);}
int main()
{
 	scanf("%d%d%d",&n,&m,&s);
 	for(int i=1;i<=s;i++)scanf("%d",&c[i]);
 	for(int i=1,j=1,t=c[1];i<=n;i++)
 	{
	 		a[i]=j;
	 		p[j]=i;
	 		if(t==i)t+=c[++j];
	}
	for(int i=1;i<=s;i++)for(int j=1;j<=s;j++)f[i][j]=(i==j)?0:inf;
	for(int i=1;i<=n;i++)g[i]=i;
	for(int i=1,x,y,u;i<=m;i++)
	{
	 		scanf("%d%d%d",&x,&y,&u);
	 		f[a[x]][a[y]]=f[a[y]][a[x]]=min(u,f[a[x]][a[y]]);
	 		if(!u&&find(y))g[find(x)]=find(y);
	}
	for(int i=1;i<=n;i++)if(find(i)!=find(p[a[i]])){printf("No\n");return 0;}
	printf("Yes\n");
	for(int k=1;k<=s;k++)for(int i=1;i<=s;i++)for(int j=1;j<=s;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=s;i++)
	 		for(int j=1;j<=s;j++){printf("%d ",f[i][j]==inf?-1:f[i][j]);if(j==s)printf("\n");}
	return 0;
}