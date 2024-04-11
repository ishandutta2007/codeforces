#include <bits/stdc++.h>

using namespace std;

long long n,a[10],dp[2][169],fc[169],ifc[169],pwk,dv=1e9+7;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

long long cb(long long x,long long y)
{
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,j,r,ii,k,sm,z=0;
	
	scanf("%lld",&n);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=0;i<10;i++)
	{
		scanf("%lld",a+i);
	}
	for(ii=1;ii+1;ii--)
	{
		for(i=0;i<=n-ii;i++)
		{
			dp[0][i]=0;
		}
		dp[0][0]=1;
		sm=0;
		for(i=0;i<10;i++)
		{
			k=max(a[i]-(!i&&ii),0ll);
			for(j=0;j<=n-ii;j++)
			{
				dp[1][j]=0;
				for(r=k;r<=j;r++)
				{
					dp[1][j]=(dp[1][j]+dp[0][j-r]*cb(j,r))%dv;
				}
			}
			for(j=0;j<=n-ii;j++)
			{
				dp[0][j]=dp[1][j];
				if(i==9&&j+ii)
				{
					sm=(sm+dp[0][j])%dv;
				}
			}
		}
		z=(sm+dv-z)%dv;
	}
	printf("%lld\n",z);
}