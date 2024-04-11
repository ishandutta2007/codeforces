#include <bits/stdc++.h>

using namespace std;

long long n,a[569],dp[569][569],rs[569][569];

long long bf(long long lh,long long rh)
{
	if(dp[lh][rh]==-1)
	{
		long long i,k;
		
		dp[lh][rh]=rh-lh+1;
		rs[lh][rh]=a[lh];
		for(i=lh;i<rh;i++)
		{
			k=bf(lh,i)+bf(i+1,rh);
			if(bf(lh,i)==1&&bf(i+1,rh)==1&&rs[lh][i]==rs[i+1][rh])
			{
				k--;
				rs[lh][rh]=rs[lh][i]+1;
			}
			dp[lh][rh]=min(dp[lh][rh],k);
		}
	}
	return dp[lh][rh];
}

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=i;j<=n;j++)
		{
			dp[i][j]=-1;
		}
	}
	printf("%lld\n",bf(1,n));
}