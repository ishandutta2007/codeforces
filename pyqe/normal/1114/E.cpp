#include <bits/stdc++.h>

using namespace std;

const long long ma=1e9;
long long n,d=60;

long long rnd2()
{
	return (long long)rand()<<15^rand();
}

int main()
{
	long long n,k,lh,rh,md,zz,gd=0;
	
	srand(time(NULL));
	scanf("%lld",&n);
	for(zz=ma,lh=0,rh=ma-1;lh<=rh;)
	{
		md=(lh+rh)/2;
		d--;
		printf("> %lld\n",md);
		fflush(stdout);
		scanf("%lld",&k);
		if(!k)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	for(;d;d--)
	{
		printf("? %lld\n",rnd2()%n+1);
		fflush(stdout);
		scanf("%lld",&k);
		gd=__gcd(gd,zz-k);
	}
	printf("! %lld %lld\n",zz-gd*(n-1),gd);
	fflush(stdout);
}