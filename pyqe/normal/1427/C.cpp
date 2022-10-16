#include <bits/stdc++.h>

using namespace std;

long long ln,n,a[100069],vy[100069],vx[100069],dp[100069],inf=1e18;

int main()
{
	long long i,j,r,mx=-inf,z=0;
	
	scanf("%lld%lld",&ln,&n);
	vy[0]=1;
	vx[0]=1;
	for(j=0,i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",a+i,vy+i,vx+i);
		for(;j<i&&a[i]-a[j]>=ln*2-2;j++)
		{
			mx=max(mx,dp[j]);
		}
		dp[i]=mx+1;
		for(r=j;r<i;r++)
		{
			if(abs(vy[i]-vy[r])+abs(vx[i]-vx[r])<=a[i]-a[r])
			{
				dp[i]=max(dp[i],dp[r]+1);
			}
		}
		z=max(z,dp[i]);
	}
	printf("%lld\n",z);
}