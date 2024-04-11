#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=1e3,inf=1e18;
long long n,d,nr[1069],a[1069],wg[1069],dp[12069];
queue<long long> q;

int main()
{
	long long t,rr,i,j,k,l,z;
	
	for(i=1;i<=ma;i++)
	{
		nr[i]=inf;
	}
	q.push(1);
	nr[1]=0;
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		for(i=1;i<=k;i++)
		{
			l=k+k/i;
			if(l<=ma&&nr[k]+1<nr[l])
			{
				q.push(l);
				nr[l]=nr[k]+1;
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",wg+i);
		}
		d=min(d,ma*12);
		for(i=0;i<=d;i++)
		{
			dp[i]=-inf;
		}
		dp[0]=0;
		for(i=1;i<=n;i++)
		{
			for(j=d;j>=nr[a[i]];j--)
			{
				dp[j]=max(dp[j],dp[j-nr[a[i]]]+wg[i]);
			}
		}
		z=-inf;
		for(i=0;i<=d;i++)
		{
			z=max(z,dp[i]);
		}
		printf("%lld\n",z);
	}
}