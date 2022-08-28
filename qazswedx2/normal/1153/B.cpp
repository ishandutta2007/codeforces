#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,h,f[100005],g[100005],d[1005][1005];
int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=m;i++)
		scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&g[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&d[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(d[i][j]==0) printf("0 ");
			else printf("%d ",min(g[i],f[j]));
		printf("\n");
	}
	return 0;
}