#include <bits/stdc++.h>

using namespace std;

long long n,a[2069],il=0;
unordered_map<long long,long long> fq;

int main()
{
	long long i,lh,rh,md,z;
	bool bad;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		fq[a[i]]++;
		if(fq[a[i]]==2)
		{
			il++;
		}
	}
	lh=0;
	rh=n;
	for(md=(lh+rh)/2;lh<=rh;md=(lh+rh)/2)
	{
		bad=1;
		for(i=0;i<n+md;i++)
		{
			if(i<n)
			{
				fq[a[i]]--;
				if(fq[a[i]]==1)
				{
					il--;
				}
			}
			if(i>=md)
			{
				fq[a[i-md]]++;
				if(fq[a[i-md]]==2)
				{
					il++;
				}
			}
			if(i>=md-1&&i<n)
			{
				if(il==0)
				{
					bad=0;
				}
			}
		}
		if(bad)
		{
			lh=md+1;
		}
		else
		{
			z=md;
			rh=md-1;
		}
	}
	printf("%lld\n",z);
}