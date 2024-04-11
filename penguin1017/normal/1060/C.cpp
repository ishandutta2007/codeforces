#include<iostream>
using namespace std;
#define inf (long long)1e18
#define N (int)2e3+2
int a[N],b[N];
long long amin[N],bmin[N];
int main()
{
	int n,m,i,j,num;
	long long min1=inf,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		min1=min1<num?min1:num;
		a[i]=a[i-1]+num;
	}
	amin[1]=min1;
	min1=inf;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&num);
		min1=min1<num?min1:num;
		b[i]=b[i-1]+num;
	}
	scanf("%lld",&x);
	bmin[1]=min1;
	for(i=2;i<=n;i++)
	{
		min1=inf;
		for(j=i;j<=n;j++)
		{
			long long cha=a[j]-a[j-i];
			min1=min1<cha?min1:cha;
		}
		amin[i]=min1;
	}
	for(i=2;i<=m;i++)
	{
		min1=inf;
		for(j=i;j<=m;j++)
		{
			long long cha=b[j]-b[j-i];
			min1=min1<cha?min1:cha;
		}
		bmin[i]=min1;
	}
	int max=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(amin[i]*bmin[j]<=x)
			{
				int ji=i*j;
				max=max>ji?max:ji;
			}
		}
	}
	cout<<max;
}