#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n;

int main()
{
	long long t,rr,i,j,k,sm,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		mn=inf;
		for(i=1;i<=n*2;i++)
		{
			for(j=1;j<=n*2;j++)
			{
				scanf("%lld",&k);
				if(i>n&&j>n)
				{
					sm+=k;
				}
				if((i>n^j>n)&&(i%n==1||i%n==0)&&(j%n==1||j%n==0))
				{
					mn=min(mn,k);
				}
			}
		}
		printf("%lld\n",sm+mn);
	}
}