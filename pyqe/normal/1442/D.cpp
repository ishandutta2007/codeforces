#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[3069],dp[13][3069],z=0;
vector<long long> vl[3069];

void dnc(long long cdh,long long lh,long long rh)
{
	if(lh==rh)
	{
		long long i;
		
		for(i=0;i<=min(fq[lh],d);i++)
		{
			z=max(z,vl[lh][i]+dp[cdh][d-i]);
		}
	}
	else
	{
		long long i,j,ii,md=(lh+rh)/2,lb,rb;
		
		for(ii=0;ii<2;ii++)
		{
			lb=!ii?lh:md+1;
			rb=!ii?md:rh;
			for(i=0;i<=d;i++)
			{
				dp[cdh+1][i]=dp[cdh][i];
			}
			for(i=lh;i<=rh;i++)
			{
				if(i<lb||i>rb)
				{
					for(j=d;j>=fq[i];j--)
					{
						dp[cdh+1][j]=max(dp[cdh+1][j],dp[cdh+1][j-fq[i]]+vl[i][fq[i]]);
					}
				}
			}
			dnc(cdh+1,lb,rb);
		}
	}
}

int main()
{
	long long i,j,k,sm;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",fq+i);
		sm=0;
		for(j=0;j<=fq[i];j++)
		{
			k=0;
			if(j)
			{
				scanf("%lld",&k);
			}
			sm+=k;
			vl[i].push_back(sm);
		}
	}
	dnc(0,1,n);
	printf("%lld\n",z);
}