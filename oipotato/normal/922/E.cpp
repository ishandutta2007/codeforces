#include<cstdio>
#include<algorithm>
using namespace std;
const long long inf=2000000000ll*10000000;
long long f[1010][10010];
int c[1010],n,W,B,X,cost[1010];
int main()
{
	scanf("%d%d%d%d",&n,&W,&B,&X);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		c[i]=c[i-1]+x;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&cost[i]);
	}
	for(int i=1;i<=c[n];i++)
	{
		f[0][i]=-inf;
	}
	f[0][0]=W;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=c[n];j++)
		{
			f[i][j]=-inf;
		}
		for(int j=0;j<=c[i];j++)
		{
			int len=c[i]-c[i-1];
			for(int k=0;k<=len&&k<=j;k++)
			{
				f[i][j]=max(f[i][j],min(f[i-1][j-k]+X,W+1ll*(j-k)*B)-1ll*cost[i]*k);
			}
		}
		for(int j=0;j<=c[i];j++)
		{
			if(f[i][j]<0)
			{
				f[i][j]=-inf;
			}
		}
	}
	for(int i=c[n];i>=0;i--)
	{
		if(f[n][i]>=0)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}