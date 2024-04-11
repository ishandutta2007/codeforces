#include <bits/stdc++.h>

using namespace std;

long long n,ub,d,d2;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&ub,&d,&d2);
		z=0;
		k=0;
		for(i=0;i<n;i++)
		{
			if(k+d<=ub)
			{
				k+=d;
			}
			else
			{
				k-=d2;
			}
			z+=k;
		}
		printf("%lld\n",z);
	}
}