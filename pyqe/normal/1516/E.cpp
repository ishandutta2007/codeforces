#include <bits/stdc++.h>

using namespace std;

const long long ma=200,dv=1e9+7;
long long n,d,fc[469],ifc[469],dp[469][269],pc[469],sq[469],pwk;

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

int main()
{
	long long i,j,r;
	
	fc[0]=1;
	ifc[0]=1;
	dp[0][0]=1;
	for(i=1;i<=ma*2;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
		for(j=1;j<=ma;j++)
		{
			for(r=2;r<=min(i,j+1);r++)
			{
				dp[i][j]=(dp[i][j]+dp[i-r][j-r+1]*fc[i-1]%dv*ifc[i-r])%dv;
			}
		}
	}
	scanf("%lld%lld",&n,&d);
	for(i=0;i<=d*2;i++)
	{
		pc[i]=1;
		for(j=1;j<=i;j++)
		{
			pc[i]=pc[i]*(n+1-j)%dv;
		}
		pc[i]=pc[i]*ifc[i]%dv;
	}
	for(i=0;i<=d;i++)
	{
		sq[i]=0;
		if(i>=2)
		{
			sq[i]=sq[i-2];
		}
		for(j=0;j<=i*2;j++)
		{
			sq[i]=(sq[i]+dp[j][i]*pc[j])%dv;
		}
		if(i)
		{
			printf("%lld%c",sq[i]," \n"[i==d]);
		}
	}
}