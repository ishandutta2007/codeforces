#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dp[5069][5069],pwk,dv=998244353;

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
	long long i,j,dn,k=1,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	dp[0][0]=1;
	for(i=1;i<=d;i++)
	{
		for(j=1;j<=d;j++)
		{
			dp[i][j]=(dp[i-1][j-1]*(n-j+1)+dp[i-1][j]*j)%dv;
		}
	}
	dn=pw(m,dv-2);
	for(i=1;i<=d;i++)
	{
		k=k*dn%dv;
		z=(z+dp[d][i]*k)%dv;
	}
	printf("%lld\n",z);
}