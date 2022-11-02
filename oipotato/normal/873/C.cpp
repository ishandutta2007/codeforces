#include<cstdio>
#include<algorithm>
using namespace std;
int a[110][110],ans1,ans2,n,m,k;
void cal(int x)
{
	int now=0,num=0,tans1,tans2;
	for(int i=1;i<=k;i++)
	{
		now+=a[i][x];
	}
	tans1=now;
	tans2=0;
	for(int i=2;i<=n-k+1;i++)
	{
		now-=a[i-1][x];
		now+=a[i+k-1][x];
		num+=a[i-1][x];
		if(now>tans1)
		{
			tans1=now;
			tans2=num;
		}
	}
	ans1+=tans1;
	ans2+=tans2;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cal(i);
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}