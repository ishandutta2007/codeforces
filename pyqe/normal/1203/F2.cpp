#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,nn,dp[169][60069];
pair<long long,long long> an[169];
priority_queue<pair<long long,long long>> pq;

bool dif(pair<long long,long long> p1,pair<long long,long long> p2)
{
	long long df1,df2;
	
	df1=p1.fr+p1.sc;
	df2=p2.fr+p2.sc;
	if(df1==df2)
	{
		return p1.fr>p2.fr;
	}
	else
	{
		return df1>df2;
	}
}

int main()
{
	long long i,j,jj,k,l,mx=0,c=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(l>=0)
		{
			pq.push({-k,l});
		}
		else
		{
			nn++;
			an[nn]={k,l};
		}
	}
	for(;!pq.empty()&&-pq.top().fr<=d;pq.pop())
	{
		d+=pq.top().sc;
		c++;
	}
	sort(an+1,an+nn+1,dif);
	for(i=0;i<=d;i++)
	{
		dp[0][i]=-1e18;
	}
	dp[0][d]=0;
	for(i=0;i<nn;i++)
	{
		for(j=0;j<=d;j++)
		{
			dp[i+1][j]=dp[i][j];
			jj=j+an[i+1].sc;
			if(j>=an[i+1].fr)
			{
				if(jj>=0)
				{
					dp[i+1][jj]=max(dp[i+1][jj],dp[i][j]+1);
				}
			}
			mx=max(mx,dp[i][j]);
		}
	}
	for(i=0;i<=d;i++)
	{
		mx=max(mx,dp[nn][i]);
	}
	printf("%lld\n",mx+c);
}