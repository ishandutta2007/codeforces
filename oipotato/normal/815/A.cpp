#include<cstdio>
using namespace std;
int a[110][110],row[110],col[110],ansrow[110],anscol[110],n,m,tans,ans;
bool flag;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&a[i][j]);
	ans=10000000;
	for(int i=0;i<=500;i++)
	{
		row[1]=i;
		flag=1;
		for(int j=1;j<=m;j++)
		if(a[1][j]<i)
		{
			flag=0;
			break;
		}
		else col[j]=a[1][j]-i;
		if(!flag)break;
		for(int j=2;j<=n;j++)
		{
			if(a[j][1]-col[1]<0)
			{
				flag=0;
				break;
			}
			row[j]=a[j][1]-col[1];
			for(int k=2;k<=m;k++)
			if(a[j][k]-col[k]!=row[j])
			{
				flag=0;
				break;
			}
			if(!flag)break;
		}
		if(!flag)continue;
		tans=0;
		for(int j=1;j<=n;j++)tans+=row[j];
		for(int j=1;j<=m;j++)tans+=col[j];
		if(tans<ans)
		{
			ans=tans;
			for(int j=1;j<=n;j++)ansrow[j]=row[j];
			for(int j=1;j<=m;j++)anscol[j]=col[j];
		}
	}
	if(ans==10000000)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=ansrow[i];j++)
	printf("row %d\n",i);
	for(int i=1;i<=m;i++)
	for(int j=1;j<=anscol[i];j++)
	printf("col %d\n",i);
	return 0;
}