#include <bits/stdc++.h>

using namespace std;

long long n,ma=100,fq[169],inf=1e18;
bitset<10069> dp[2][169];

int main()
{
	long long i,j,r,k,c=0,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		c+=!fq[k];
		fq[k]++;
	}
	for(i=1;i<=ma;i++)
	{
		for(j=0;j<fq[i];j++)
		{
			for(r=n;r;r--)
			{
				dp[1][r]|=(dp[1][r-1]|dp[0][r-1])<<i;
			}
		}
		for(j=1;j<=fq[i];j++)
		{
			dp[0][j][j*i]=1;
		}
	}
	for(i=1;i<=ma;i++)
	{
		for(j=1;j<=fq[i];j++)
		{
			if(!dp[1][j][j*i])
			{
				if(c>2||j<fq[i])
				{
					z=max(z,j);
				}
				else
				{
					z=n;
				}
			}
		}
	}
	printf("%lld\n",z);
}