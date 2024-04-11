#include <bits/stdc++.h>

using namespace std;

long long n[2],d;

int main()
{
	long long i,ii,k,mn=1e18,mx=-1e18;
	
	scanf("%lld%lld%lld",n,n+1,&d);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<n[ii];i++)
		{
			scanf("%lld",&k);
			if(!ii)
			{
				mn=min(mn,k);
			}
			else
			{
				mx=max(mx,k);
			}
		}
	}
	printf("%lld\n",max(d/mn*mx+d%mn,d));
}