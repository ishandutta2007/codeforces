#include <bits/stdc++.h>

using namespace std;

long long n,mn[49],mx[49],inf=1e18;

int main()
{
	long long i,j,sm,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<49;i++)
	{
		mn[i]=inf;
		mx[i]=-inf;
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<49;j++)
		{
			sm=i*4+j*9;
			if(i+j<=n)
			{
				mn[sm%49]=min(mn[sm%49],sm/49);
				mx[sm%49]=max(mx[sm%49],sm/49+n-i-j);
			}
		}
	}
	for(i=0;i<49;i++)
	{
		z+=max(mx[i]-mn[i]+1,0ll);
	}
	printf("%lld\n",z);
}