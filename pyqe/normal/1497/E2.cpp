#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=1e7;
long long n,d,pc[10000069],a[200069],ls[10000069];
pair<long long,long long> dp[69];

int main()
{
	long long t,rr,i,j;
	
	for(i=1;i<=ma;i++)
	{
		pc[i]=i;
	}
	for(i=2;i<=ma;i++)
	{
		for(j=i*i;j<=ma;j+=i*i)
		{
			for(;pc[j]%(i*i)==0;pc[j]/=i*i);
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<=d;i++)
		{
			dp[i]={0,0};
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			a[i]=pc[a[i]];
			for(j=d;j+1;j--)
			{
				if(ls[a[i]]>-dp[j].sc)
				{
					dp[j+1]=min(dp[j+1],dp[j]);
					dp[j]={dp[j].fr+1,1-i};
				}
			}
			ls[a[i]]=i;
		}
		printf("%lld\n",dp[d].fr+1);
		for(i=1;i<=n;i++)
		{
			ls[a[i]]=0;
		}
	}
}