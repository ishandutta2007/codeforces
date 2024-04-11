#include <bits/stdc++.h>

using namespace std;

long long n,a[2069],pst[2069],sq[5069],zs;

void rev(long long x)
{
	long long i;
	
	if(x==1)
	{
		return;
	}
	zs++;
	sq[zs]=x;
	for(i=1;i<x+1-i;i++)
	{
		swap(a[i],a[x+1-i]);
		swap(pst[a[i]],pst[a[x+1-i]]);
	}
}

int main()
{
	long long t,rr,i;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		bad=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			bad|=a[i]%2!=i%2;
			pst[a[i]]=i;
		}
		if(bad)
		{
			printf("-1\n");
			continue;
		}
		zs=0;
		for(i=n;i-1;i-=2)
		{
			rev(pst[i]);
			rev(pst[i-1]-1);
			rev(pst[i-1]+1);
			rev(3);
			rev(i);
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}