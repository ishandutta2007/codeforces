#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e9,a[100069],inf=1e18;

int main()
{
	long long i,j,ml,sm,z=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i;i++)
	{
		ml=1;
		sm=0;
		for(j=1;j<=n;j++)
		{
			if(ml>n*ma*2)
			{
				sm=inf;
				i=-1;
				break;
			}
			sm+=abs(a[j]-ml);
			ml*=i;
		}
		z=min(z,sm);
	}
	printf("%lld\n",z);
}