#include <bits/stdc++.h>

using namespace std;

long long fq[2],inf=1e18;

int main()
{
	long long t,rr,i,ii,k,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
		}
		mn=inf;
		for(i=0;i<4;i++)
		{
			scanf("%lld",&k);
			fq[k%2]++;
			if(i<3)
			{
				mn=min(mn,k);
			}
		}
		if(fq[1]<=1||(mn&&fq[0]<=1))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}