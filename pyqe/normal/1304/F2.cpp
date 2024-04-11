#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,mm,a[69][20069],ps[69][2][20069],dp[2][20069],px[2][20069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,j,ii,jj,u,mx,z=-1e18;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	mm=m-d+1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(j=1+(m-1)*ii;j!=(m+1)*!ii;j+=u)
			{
				ps[i][ii][j]=ps[i][ii][j-u]+a[i][j];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i>1)
		{
			for(ii=0;ii<2;ii++)
			{
				mx=-1e18;
				for(j=1+(mm-1)*ii;j!=(mm+1)*!ii;j+=!ii*2-1)
				{
					mx=max(mx,dp[0][j]);
					px[ii][j]=mx;
				}
			}
			for(j=1;j<=mm;j++)
			{
				dp[1][j]=-1e18;
				if(j-d>0)
				{
					dp[1][j]=max(dp[1][j],px[0][j-d]);
				}
				if(j+d<=mm)
				{
					dp[1][j]=max(dp[1][j],px[1][j+d]);
				}
			}
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				for(j=1+(m-1)*ii;j!=(m+1)*!ii;j+=u)
				{
					if(j>(d-1)*ii&&j<=mm+(d-1)*ii)
					{
						pq.push({dp[0][j-(d-1)*ii]+ps[i][ii][j-u],j-(d-1)*ii});
					}
					for(;pq.top().sc<=j-d||pq.top().sc>j;pq.pop());
					jj=j-(d-1)*!ii;
					if(jj>0&&jj<=mm)
					{
						dp[1][jj]=max(dp[1][jj],pq.top().fr-ps[i][ii][j]);
					}
				}
				for(;!pq.empty();pq.pop());
			}
		}
		for(j=1;j<=mm;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[1][j]+=ps[i+ii][0][j+d-1]-ps[i+ii][0][j-1];
			}
		}
		for(j=1;j<=mm;j++)
		{
			dp[0][j]=dp[1][j];
			if(i==n)
			{
				z=max(z,dp[0][j]);
			}
		}
	}
	printf("%lld\n",z);
}