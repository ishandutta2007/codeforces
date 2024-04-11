#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[100069];
pair<long long,long long> dp[100069];

int main()
{
	long long i,j,sm,c,lh,rh,md,zz,zm,z;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(lh=0,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(j=0,i=1;i<=n;i++)
		{
			for(;j<n&&a[j+1]<a[i]-5;j++);
			dp[i]=max(dp[i-1],{dp[j].fr+i-j-md,dp[j].sc-1});
		}
		sm=dp[n].fr;
		c=-dp[n].sc;
		if(c<=d)
		{
			zz=md;
			zm=sm;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	z=zm+zz*d;
	printf("%lld\n",z);
}