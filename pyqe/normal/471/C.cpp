#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,lh,rh,md,zz=0,k;
	
	scanf("%lld",&n);
	for(lh=1,rh=1e7;lh<=rh;)
	{
		md=(lh+rh)/2;
		k=md*3-n%3;
		if(k*2+k*(k-1)/2*3<=n)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zz);
}