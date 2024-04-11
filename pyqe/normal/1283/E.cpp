#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long i,mn=0,mx=0,ls,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	ls=-1e18;
	for(i=1;i<=n;i++)
	{
		if(a[i]-ls>2)
		{
			mn++;
			ls=a[i];
		}
	}
	ls=-1e18;
	for(i=1;i<=n;i++)
	{
		k=max(a[i]-1,ls+1);
		if(k<=a[i]+1)
		{
			mx++;
			ls=k;
		}
	}
	printf("%lld %lld\n",mn,mx);
}