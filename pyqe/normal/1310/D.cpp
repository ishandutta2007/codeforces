#include <bits/stdc++.h>

using namespace std;

const int t=1e4;
const long long inf=1e18;
int n,d,nn[2],am[169][169],ex[2][169];
long long dp[169];

int main()
{
	int rr,i,j,r,ii,k,l,e;
	long long z=inf;
	
	srand(time(NULL));
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&am[i][j]);
		}
	}
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			e=0;
			if(i>1)
			{
				e=rand()&1;
			}
			nn[e]++;
			ex[e][nn[e]]=i;
		}
		for(i=1;i<=nn[1];i++)
		{
			k=ex[1][i];
			dp[k]=am[1][k];
		}
		for(e=0,i=2;i<d;i++,e^=1)
		{
			for(j=1;j<=nn[e];j++)
			{
				k=ex[e][j];
				dp[k]=inf;
				for(r=1;r<=nn[!e];r++)
				{
					l=ex[!e][r];
					dp[k]=min(dp[k],dp[l]+am[l][k]);
				}
			}
		}
		for(i=1;i<=nn[1];i++)
		{
			k=ex[1][i];
			z=min(z,dp[k]+am[k][1]);
		}
	}
	printf("%lld\n",z);
}