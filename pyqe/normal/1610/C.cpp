#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dp[200069];
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,k,l,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&k,&l);
			a[i]={k,l};
		}
		for(zz=1,lh=2,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			for(i=1;i<=n;i++)
			{
				dp[i]=dp[i-1]+(a[i].sc>=dp[i-1]&&dp[i-1]+1+a[i].fr>=md);
			}
			if(dp[n]>=md)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		printf("%lld\n",zz);
	}
}