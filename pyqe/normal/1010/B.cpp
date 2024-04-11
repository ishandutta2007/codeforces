#include <bits/stdc++.h>

using namespace std;

long long n,d;
bitset<69> a;

int main()
{
	long long i,k,lh,rh,md,zz;
	
	scanf("%lld%lld",&d,&n);
	for(i=1;i<=n;i++)
	{
		printf("%lld\n",d);
		fflush(stdout);
		scanf("%lld",&k);
		if(!k)
		{
			return 0;
		}
		a[i]=k==-1;
	}
	for(i=1,lh=1,rh=d;lh<=rh;i=i%n+1)
	{
		md=(lh+rh)/2;
		printf("%lld\n",md);
		fflush(stdout);
		scanf("%lld",&k);
		if(!k)
		{
			return 0;
		}
		if(!a[i])
		{
			k*=-1;
		}
		if(k==-1)
		{
			rh=md-1;
		}
		else if(k==1)
		{
			lh=md+1;
		}
	}
}