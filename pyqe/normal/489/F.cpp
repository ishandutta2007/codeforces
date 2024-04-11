#include <bits/stdc++.h>

using namespace std;

long long n,m,a[569],fq[3],dp[569][569],dv;

int main()
{
	long long i,j;
	char ch;
	
	scanf("%lld%lld%lld",&n,&m,&dv);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf(" %c",&ch);
			a[j]+=ch-'0';
		}
	}
	for(i=1;i<=n;i++)
	{
		fq[a[i]]++;
	}
	for(i=fq[0];i+1;i--)
	{
		for(j=n;j+1;j--)
		{
			if(i==fq[0]&&j==fq[1])
			{
				dp[i][j]=1;
			}
			else
			{
				dp[i][j]=(dp[i][j+2]*((j+2)*(j+1)/2)+dp[i+1][j]*(i+1)*j)%dv;
				if(j>=2)
				{
					dp[i][j]=(dp[i][j]+dp[i+2][j-2]*((i+2)*(i+1)/2))%dv;
				}
			}
		}
	}
	printf("%lld\n",dp[0][0]);
}