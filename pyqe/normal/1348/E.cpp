#include <bits/stdc++.h>
 
using namespace std;
 
int n,d,dp[2][569],inf=1e9;
long long ttl=0;
 
int main()
{
	int i,j,r,k,l,w,tg,sm=0,z=-inf;
	
	scanf("%d%d",&n,&d);
	for(i=1;i<d;i++)
	{
		dp[0][i]=-inf;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&k,&l);
		ttl+=(long long)max(k/d-1,0)+max(l/d-1,0);
		k=min(k%d+d,k);
		l=min(l%d+d,l);
		for(j=0;j<d;j++)
		{
			dp[1][j]=-inf;
			for(r=0;r<=min(k,d-1);r++)
			{
				tg=(j+d-r)%d;
				w=(k+l-r)%d;
				if(w<=l)
				{
					dp[1][j]=max(dp[1][j],dp[0][tg]+(k+l-r)/d+(j<r)+((sm+d-tg)%d+w>=d));
				}
			}
		}
		for(j=0;j<d;j++)
		{
			dp[0][j]=dp[1][j];
		}
		sm=(sm+k+l)%d;
	}
	for(i=0;i<d;i++)
	{
		z=max(z,dp[0][i]);
	}
	printf("%lld\n",ttl+z);
}