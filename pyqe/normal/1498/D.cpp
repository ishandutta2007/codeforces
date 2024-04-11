#include <bits/stdc++.h>

using namespace std;

const long long d=1e5;
long long n,m,dp[100069],sq[100069];

int main()
{
	long long i,j,ky,k,l,w;
	
	scanf("%lld%lld",&n,&m);
	dp[0]=1;
	for(i=1;i<=m;i++)
	{
		sq[i]=n+1;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&ky,&k,&w);
		for(j=0;j<=m;j++)
		{
			dp[j]=(w+1)*!!dp[j];
		}
		for(j=0;j<=m;j++)
		{
			if(dp[j])
			{
				sq[j]=min(sq[j],i);
				if(ky==1)
				{
					l=j+(k-1)/d+1;
				}
				else
				{
					l=(j*k+d-1)/d;
				}
				if(l<=m)
				{
					dp[l]=max(dp[l],dp[j]-1);
				}
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		if(sq[i]>n)
		{
			sq[i]=-1;
		}
		printf("%lld%c",sq[i]," \n"[i==m]);
	}
}