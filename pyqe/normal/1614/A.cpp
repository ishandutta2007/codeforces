#include <bits/stdc++.h>

using namespace std;

long long n,db,ub,d,nn,as[100069];

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&db,&ub,&d);
		nn=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(k>=db&&k<=ub)
			{
				nn++;
				as[nn]=k;
			}
		}
		sort(as+1,as+nn+1);
		z=0;
		for(i=1;i<=nn;i++)
		{
			if(as[i]<=d)
			{
				z++;
				d-=as[i];
			}
		}
		printf("%lld\n",z);
	}
}