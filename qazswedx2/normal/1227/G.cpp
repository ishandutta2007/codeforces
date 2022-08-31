#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1005],f[1005][1005],b[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int x=-1,nw;
		for(int j=0;j<=n;j++)
			if(b[j]+b[(j+a[i])%(n+1)]==1)
			{
				x=j+1;
				b[j]=b[(j+a[i])%(n+1)]=1;
				break;
			}
		if(x==-1)
		{
			for(int j=0;j<=n;j++)
				if(b[j]+b[(j+a[i])%(n+1)]==0)
				{
					x=j+1;
					b[j]=b[(j+a[i])%(n+1)]=1;
					break;
				}
		}
		if(x==-1) x=1;
		for(int j=x,k=1;k<=a[i];j=j%(n+1)+1,k++)
		{
			f[j][i]=1;
			nw=j;
		}
	}
	printf("%d\n",n+1);
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d",f[i][j]);
		printf("\n");
	}
	return 0;
}