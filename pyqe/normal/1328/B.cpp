#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,lh,rh,md,zz,rm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		d--;
		for(lh=1,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(md*(md-1)/2>d)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		rm=d-(zz-1)*(zz-2)/2;
		for(i=1;i<=n;i++)
		{
			printf("%c",(char)(i==n+1-zz||i==n-rm)+'a');
		}
		printf("\n");
	}
}