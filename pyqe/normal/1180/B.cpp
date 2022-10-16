#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],inf=1e18;

int main()
{
	long long i,mn=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(a[i]>=0)
		{
			a[i]=-a[i]-1;
		}
		mn=min(mn,a[i]);
	}
	if(n%2)
	{
		for(i=1;a[i]!=mn;i++);
		a[i]=-a[i]-1;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",a[i]," \n"[i==n]);
	}
}