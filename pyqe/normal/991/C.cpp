#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,w,lh,rh,md,zz,sm;
	
	scanf("%lld",&n);
	for(lh=1,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		for(k=n;k;)
		{
			w=min(md,k);
			sm+=w;
			k-=w;
			k-=k/10;
		}
		if(sm*2>=n)
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