#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long lh,rh,md,zz=-1;
	
	scanf("%lld%lld",&n,&d);
	n--;
	d--;
	for(lh=0,rh=d;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(d*(d+1)/2-(d-md)*(d-md+1)/2>=n)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}