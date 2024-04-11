#include <bits/stdc++.h>

using namespace std;

const int ma=1e7,inf=1e9;
int n,dp[10000069],sq[10000069];

int main()
{
	int t,rr,i,j,z;
	
	for(i=1;i<=ma;i++)
	{
		sq[i]=inf;
	}
	for(i=1;i<=ma;i++)
	{
		for(j=i;j<=ma;j+=i)
		{
			dp[j]+=i;
		}
		if(dp[i]<=ma)
		{
			sq[dp[i]]=min(sq[dp[i]],i);
		}
	}
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d",&n);
		z=sq[n];
		if(z==inf)
		{
			z=-1;
		}
		printf("%d\n",z);
	}
}