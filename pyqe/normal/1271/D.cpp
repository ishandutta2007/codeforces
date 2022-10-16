#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[300069],d[300069],w[300069],dp[300069];
vector<long long> al[300069];
priority_queue<long long> pq;
bitset<300069> vtd;

int main()
{
	long long i,j,k,l,sz,z=0;
	
	scanf("%lld%lld%lld",&n,&m,d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",a+i,&k,w+i);
		d[i]=d[i-1]+k;
		al[i].push_back(i);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
	}
	dp[n+1]=1e18;
	for(i=n;i>=0;i--)
	{
		dp[i]=min(dp[i+1],d[i]-a[i+1]);
	}
	if(dp[0]<0)
	{
		printf("-1\n");
		return 0;
	}
	dp[0]=0;
	for(i=n;i>0;i--)
	{
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			if(!vtd[l])
			{
				pq.push(w[l]);
				vtd[l]=1;
			}
		}
		for(j=0;!pq.empty()&&j<dp[i]-dp[i-1];j++)
		{
			z+=pq.top();
			pq.pop();
		}
	}
	printf("%lld\n",z);
}