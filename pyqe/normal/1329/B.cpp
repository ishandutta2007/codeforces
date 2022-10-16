#include <bits/stdc++.h>

using namespace std;

long long n,dv;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&dv);
		z=1;
		for(i=0;i<30;i++)
		{
			k=min(max(n-(1ll<<i)+1,0ll),1ll<<i);
			z=z*(k+1)%dv;
		}
		z=(z+dv-1)%dv;
		printf("%lld\n",z);
	}
}