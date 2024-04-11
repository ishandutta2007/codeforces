#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,ii,k,sz,sm,mx[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&sz);
			sm=0;
			mx[ii]=0;
			for(i=0;i<sz;i++)
			{
				scanf("%lld",&k);
				sm+=k;
				mx[ii]=max(mx[ii],sm);
			}
		}
		printf("%lld\n",mx[0]+mx[1]);
	}
}