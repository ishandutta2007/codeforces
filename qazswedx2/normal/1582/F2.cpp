#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],m,lim,b[5005][9005],bt[5005],f[9005];
void ins(int x,int y)
{
	for(int i=y+1;i<f[x];i++)
		b[i][++bt[i]]=x;
	f[x]=y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		m=max(m,a[i]);
	}
	lim=1;
	while(lim<=m) lim<<=1;
	for(int i=0;i<lim;i++)
		f[i]=m+1;
	ins(0,0);
	for(int i=1;i<=n;i++)
	{
		int u=a[i];
		for(int j=1;j<=bt[u];j++)
		{
			int v=b[u][j];
			if(f[v^u]>u) ins(v^u,u);
		}
		bt[u]=0;
	}
	int ct=0;
	for(int i=0;i<lim;i++)
		if(f[i]<=m)
			ct++;
	printf("%d\n",ct);
	for(int i=0;i<lim;i++)
		if(f[i]<=m)
			printf("%d ",i);
	printf("\n");
	return 0;
}