#include <bits/stdc++.h>

using namespace std;

long long a[3],inf=1e18;

int main()
{
	long long i,k,mx,sm;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",a+i);
	}
	printf("First\n");
	for(;1;)
	{
		mx=-inf;
		sm=0;
		for(i=0;i<3;i++)
		{
			mx=max(mx,a[i]);
			sm+=a[i];
		}
		printf("%lld\n",mx*3-sm);
		fflush(stdout);
		scanf("%lld",&k);
		k--;
		if(a[k]!=mx)
		{
			break;
		}
		a[k]+=mx*3-sm;
	}
	printf("%lld\n",mx*2-sm+a[k]);
	fflush(stdout);
}