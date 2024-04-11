#include<cstdio>
using namespace std;
int X,d;
long long ans[40];
int main()
{
	scanf("%d%d",&X,&d);
	int cnt=0;
	long long now=1;
	for(int i=30;i;i--)
	{
		for(;X>=(1<<i)-1;X-=(1<<i)-1)
		{
			for(int j=1;j<=i;j++)
			{
				ans[++cnt]=now;
			}
			now+=d;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%lld%c",ans[i],i==cnt?'\n':' ');
	}
	return 0;
}