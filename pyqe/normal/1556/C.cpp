#include <bits/stdc++.h>

using namespace std;

long long n,ps[1069];

int main()
{
	long long i,j,u,mn,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",ps+i);
		u=i%2*2-1;
		ps[i]=ps[i-1]+ps[i]*u;
	}
	for(i=0;i<n;i+=2)
	{
		mn=ps[i+1]-ps[i]-1;
		for(j=i+2;j<=n;j++)
		{
			z+=max(mn-max(ps[j]-ps[i],0ll)+1,0ll);
			mn=min(mn,ps[j]-ps[i]);
		}
	}
	printf("%lld\n",z);
}