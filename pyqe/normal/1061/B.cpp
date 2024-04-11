#include <bits/stdc++.h>

using namespace std;

long long n,m,ttl=0,a[100069],tmp[100069],inf=1e18;

int main()
{
	long long i,mx=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]<n)
	{
		for(i=1;i<=n;i++)
		{
			tmp[a[n]+1-a[i]]++;
		}
		n=a[n];
		for(i=1;i<=n;i++)
		{
			a[i]=a[i-1]+tmp[i];
		}
	}
	for(i=1;i<=n;i++)
	{
		mx=max(mx,i-a[i]);
	}
	printf("%lld\n",ttl-(a[n]+mx));
}