#include <bits/stdc++.h>

using namespace std;

long long n,m,dp[169],wg[169];

int main()
{
	long long i,j,r,k,p;
	
	scanf("%lld%lld",&n,&m);
	for(i=2;i<=m;i++)
	{
		k=i;
		for(j=2;j<=n;j++)
		{
			if(n%j==0)
			{
				for(;k%j==0;k/=j);
			}
		}
		if(k==1)
		{
			dp[i]=2;
			for(k=1;k%i;k*=n,wg[i]++);
			continue;
		}
		if((n-1)%i==0)
		{
			dp[i]=3;
			continue;
		}
		if((n+1)%i==0)
		{
			dp[i]=11;
			continue;
		}
		dp[i]=7;
		for(j=1;j<=i;j++)
		{
			for(r=1;r<=i;r++)
			{
				k=j/__gcd(j,r)*r;
				if(i%k==0)
				{
					p=i/k;
					if((j==1||dp[j]==3)&&(r==1||dp[r]==11)&&(p==1||dp[p]==2))
					{
						dp[i]=6;
						break;
					}
				}
			}
			if(r<=i)
			{
				break;
			}
		}
	}
	printf("%lld-type\n",dp[m]);
	if(dp[m]==2)
	{
		printf("%lld\n",wg[m]);
	}
}