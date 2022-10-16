#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,k,l,lh,rh,md,crn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		lh=1;
		rh=1000000;
		for(;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(md*md*md>=k*l)
			{
				crn=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		if(crn*crn*crn!=k*l||__gcd(k,l)%crn!=0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}