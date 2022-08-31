#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[100005],b[100005],f[1005][1005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&f[i][j]);
	for(int i=0;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			if(j<=i) b[j]=f[1][j];
			else b[j]=f[1][j]^1;
		int tfl=1,flg=(i==m);
		for(int j=2;j<=n;j++)
		{
			int fl0=0,fl1=0,flz0=0,flz1=0;
			for(int k=1;k<=m;k++)
			{
				if((f[j][k]^b[k])==0) fl0=1,flz1=fl1;
				else fl1=1,flz0=fl0;
			}
			if(flz0&&flz1)
			{
				tfl=0;
				break;
			}
			if((flz0||flz1)&&!flg)
			{
				tfl=0;
				break;
			}
			if(!flg)
			{
				a[j]=fl0;
			}
			else
			{
				if(flz0||flz1)
				{
					flg=0;
					a[j]=flz1;
				}
				else a[j]=fl1;
			}
		}
		if(tfl)
		{
			//printf("i=%d\n",i);
			printf("YES\n");
			for(int j=1;j<=n;j++)
				printf("%d",a[j]);
			printf("\n");
			for(int j=1;j<=m;j++)
				printf("%d",b[j]);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}