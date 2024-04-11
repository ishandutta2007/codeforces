#include <bits/stdc++.h>

using namespace std;

long long n,d,dp[5069][5069],pwk,dv=1e9+7;

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
	long long i,j,z=0;
	
	scanf("%lld%lld",&n,&d);
	dp[0][0]=1;
	for(i=1;i<=d;i++)
	{
		for(j=1;j<=d;j++)
		{
			dp[i][j]=(dp[i-1][j-1]*(n-j+1)+dp[i-1][j]*j)%dv;
		}
	}
	for(i=1;i<=d;i++)
	{
		z=(z+dp[d][i]*pw(2,n-i))%dv;
	}
	printf("%lld\n",z);
}