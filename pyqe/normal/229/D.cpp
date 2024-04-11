#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[5069],ps[5069];
pair<long long,long long> dp[5069];

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ps[i]=ps[i-1]+a[i];
		for(j=0;j<i;j++)
		{
			k=ps[i]-ps[j];
			if(k>=dp[j].sc)
			{
				dp[i]=max(dp[i],{dp[j].fr+1,-k});
			}
		}
		dp[i].sc*=-1;
	}
	printf("%lld\n",n-dp[n].fr);
}