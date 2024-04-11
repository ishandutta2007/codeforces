#include <bits/stdc++.h>

using namespace std;

long long n,ls[2];

int main()
{
	long long t,rr,i,ii,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			ls[ii]=0;
		}
		for(i=1;i<=n*2;i++)
		{
			scanf("%lld",&k);
			if(!ls[k%2])
			{
				ls[k%2]=i;
			}
			else if(i<n*2)
			{
				printf("%lld %lld\n",ls[k%2],i);
				ls[k%2]=0;
			}
		}
	}
}