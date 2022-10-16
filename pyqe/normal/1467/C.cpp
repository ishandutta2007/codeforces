#include <bits/stdc++.h>

using namespace std;

long long n[3],ttl=0,sm[3],mn[3],inf=1e18;

int main()
{
	long long i,j,k;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",n+i);
	}
	for(i=0;i<3;i++)
	{
		mn[i]=inf;
		for(j=0;j<n[i];j++)
		{
			scanf("%lld",&k);
			ttl+=k;
			sm[i]+=k;
			mn[i]=min(mn[i],k);
		}
	}
	sort(sm,sm+3);
	sort(mn,mn+3);
	printf("%lld\n",ttl-min(sm[0],mn[0]+mn[1])*2);
}