#include <bits/stdc++.h>

using namespace std;

long long n,d,ps[500069];

int main()
{
	long long i,k,mx;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		if(i<=(n+1)/2+1)
		{
			scanf("%lld",&k);
			k*=-1;
		}
		ps[i]=ps[i-1]+k;
	}
	d=k;
	if(d<=0)
	{
		if(ps[n]<0)
		{
			printf("%lld\n",n);
		}
		else
		{
			printf("-1\n");
		}
		return 0;
	}
	mx=n-1;
	for(i=0;i<=(n-1)/2;i++)
	{
		k=lower_bound(ps+n/2+1,ps+n+1,ps[i])-ps-1;
		mx=min(mx+1,k);
		if(mx==n)
		{
			printf("%lld\n",n-i);
			return 0;
		}
	}
	printf("-1\n");
}