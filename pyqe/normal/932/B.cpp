#include <bits/stdc++.h>

using namespace std;

long long dp[1000069],ps[10][1000069];

int main()
{
	long long t,rr,i,j,lh,rh,k;
	
	for(i=1;i<=1000000;i++)
	{
		dp[i]=1;
		for(k=i;k;k/=10)
		{
			if(k%10)
			{
				dp[i]*=k%10;
			}
		}
		dp[i]=dp[dp[i]];
		for(j=0;j<10;j++)
		{
			ps[j][i]=ps[j][i-1];
		}
		ps[dp[i]][i]++;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&lh,&rh,&k);
		printf("%lld\n",ps[k][rh]-ps[k][lh-1]);
	}
}