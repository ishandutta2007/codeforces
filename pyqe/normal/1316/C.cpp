#include <bits/stdc++.h>

using namespace std;

long long n[2],ft[2],dv;

int main()
{
	long long i,ii,k;
	bool bad;
	
	scanf("%lld%lld%lld",n,n+1,&dv);
	for(ii=0;ii<2;ii++)
	{
		bad=0;
		for(i=0;i<n[ii];i++)
		{
			scanf("%lld",&k);
			if(!bad&&k%dv)
			{
				ft[ii]=i;
				bad=1;
			}
		}
	}
	printf("%lld\n",ft[0]+ft[1]);
}