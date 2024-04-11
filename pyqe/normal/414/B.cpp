#include <bits/stdc++.h>

using namespace std;

long long n,m,fc[2069],ifc[2069],dp[2069][2069],sq[2069],pwk,dv=1e9+7;

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
	long long i,j,r,z=0;
	
	scanf("%lld%lld",&n,&m);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=m;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=n;i;i--)
	{
		for(j=i*2;j<=n;j+=i)
		{
			for(r=2;r<=m;r++)
			{
				dp[i][r]=(dp[i][r]+dp[j][r-1])%dv;
			}
		}
		dp[i][1]=1;
		for(j=1;j<=m;j++)
		{
			z=(z+dp[i][j]*cb(m-1,j-1))%dv;
		}
	}
	printf("%lld\n",z);
}