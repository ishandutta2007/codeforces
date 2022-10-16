#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,a[5069],dp[2][5069],pwk;

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
	long long t,rr,i,j,c,p,p2,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(j=0,i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			for(;a[j+1]<a[i];j++);
			dp[0][i]=j;
		}
		for(i=2;i<=n/2;i++)
		{
			for(p2=0,p=0,j=1;j<=n;j++)
			{
				dp[1][j]=dp[1][j-1];
				for(;a[p+1]<a[j];)
				{
					p++;
					for(;a[p2+1]<a[p];p2++);
					dp[1][j]=(dp[1][j]+dp[0][p]*(p2-((i-1)*2-1)))%dv;
				}
			}
			for(j=1;j<=n;j++)
			{
				dp[0][j]=dp[1][j];
			}
		}
		z=dp[0][n];
		c=0;
		for(i=1;i<=n;i++)
		{
			c=c*(a[i]==a[i-1])+1;
			z=z*pw(c,dv-2)%dv;
		}
		printf("%lld\n",z);
	}
}