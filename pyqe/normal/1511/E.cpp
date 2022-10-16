#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,m,dp[2][300069][2],fh[2][300069],pwk;

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
	long long i,j,ii,p,c=0,yy,xx,pp,z=0;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	dp[0][0][0]=1;
	for(i=1;i<=max(n,m);i++)
	{
		for(ii=0;ii<2;ii++)
		{
			dp[0][i][ii]=dp[0][i-1][!ii];
			dp[1][i][ii]=(dp[1][i-1][!ii]+dp[0][i-1][!ii]*!ii)%dv;
		}
		dp[0][i][0]=(dp[0][i][0]+dp[0][i-1][0]+dp[0][i-1][1])%dv;
		dp[1][i][0]=(dp[1][i][0]+dp[1][i-1][0]+dp[1][i-1][1])%dv;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf(" %c",&ch);
			p=i*m+j;
			if(ch=='o')
			{
				c++;
				for(ii=0;ii<2;ii++)
				{
					yy=i-!ii;
					xx=j-ii;
					pp=yy*m+xx;
					if(yy>=0&&xx>=0)
					{
						fh[ii][p]=fh[ii][pp];
					}
					fh[ii][p]++;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			for(ii=0;ii<2;ii++)
			{
				yy=i+!ii;
				xx=j+ii;
				pp=yy*m+xx;
				if(yy>=n||xx>=m||!fh[ii][pp])
				{
					z=(z+(dp[1][fh[ii][p]][0]+dp[1][fh[ii][p]][1])*pw(2,c-fh[ii][p]))%dv;
				}
			}
		}
	}
	printf("%lld\n",z);
}