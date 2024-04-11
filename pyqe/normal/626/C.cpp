#include <bits/stdc++.h>

using namespace std;

long long n[2];

int main()
{
	long long i,lh,rh,md,sm1,sm2,z,mn=1e18;
	
	scanf("%lld%lld",n,n+1);
	for(i=0;i<=n[0];i++)
	{
		z=1e18;
		for(lh=0,rh=n[1];lh<=rh;)
		{
			md=(lh+rh)/2;
			sm1=(i+md)*6;
			sm2=(n[1]-md)*6-3;
			z=min(z,max(sm1,sm2));
			if(sm1>=sm2)
			{
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		mn=min(mn,max((n[0]-i+1)/2*6-4+(n[0]-i+1)%2*2,z));
	}
	printf("%lld\n",mn);
}