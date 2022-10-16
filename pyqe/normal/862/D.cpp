#include <bits/stdc++.h>

using namespace std;

long long n,d;

long long qr(long long x)
{
	long long i,k;
	
	printf("? ");
	for(i=1;i<=n;i++)
	{
		printf("%lld",(long long)(i>x));
	}
	printf("\n");
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

int main()
{
	long long k,lh,rh,md,zz;
	
	scanf("%lld",&n);
	d=qr(n);
	for(lh=2,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		k=(qr(md)+d-(n-md))/2;
		if(k&&md-k)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	k=(qr(zz-1)+d-(n-(zz-1)))/2;
	printf("! %lld %lld\n",zz-!k,zz-!!k);
	fflush(stdout);
}