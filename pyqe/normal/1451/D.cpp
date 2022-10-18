#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(lh=0,rh=n/m;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(md*md*m*m*2<=n*n)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		if((zz*zz+(zz+1)*(zz+1))*m*m<=n*n)
		{
			printf("Ashish\n");
		}
		else
		{
			printf("Utkarsh\n");
		}
	}
}