#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,a[569],dp[569];

int main()
{
	long long i,j,r,mx,z=0;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		if(ch=='+')
		{
			scanf("%lld",a+i);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i])
		{
			dp[0]=1;
			mx=0;
			for(j=1;j<=n;j++)
			{
				if(a[j])
				{
					if(j==i);
					else if(a[j]<a[i]||(a[j]==a[i]&&j<i))
					{
						mx++;
						dp[mx]=0;
						for(r=mx;r;r--)
						{
							dp[r]=(dp[r]+dp[r-1])%dv;
						}
					}
					else
					{
						for(r=0;r<=mx;r++)
						{
							dp[r]=dp[r]*2%dv;
						}
					}
				}
				else
				{
					if(j<i)
					{
						dp[0]=dp[0]*2%dv;
					}
					for(r=0;r<mx;r++)
					{
						dp[r]=(dp[r]+dp[r+1])%dv;
					}
				}
			}
			for(j=0;j<=mx;j++)
			{
				z=(z+a[i]*dp[j])%dv;
			}
		}
	}
	printf("%lld\n",z);
}