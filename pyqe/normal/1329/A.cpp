#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],sq[100069],inf=1e18;

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",a+i);
	}
	sq[m+1]=-inf;
	for(i=m;i;i--)
	{
		sq[i]=max(a[i],sq[i+1]+1);
	}
	if(sq[1]>n)
	{
		printf("-1\n");
		return 0;
	}
	sq[1]=n;
	for(i=2;i<=m;i++)
	{
		sq[i]=max(sq[i],sq[i-1]-a[i-1]);
	}
	if(sq[m]>a[m])
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		printf("%lld%c",sq[i]-a[i]+1," \n"[i==m]);
	}
}