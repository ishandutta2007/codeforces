#include <bits/stdc++.h>

using namespace std;

long long n,d,am[10][10][10],inf=1e18;

int main()
{
	long long t,rr,i,j,r,p,k;
	
	for(i=1;i<10;i++)
	{
		for(j=0;j<i;j++)
		{
			for(r=0;r<i;r++)
			{
				am[i][j][r]=inf;
			}
		}
		for(j=0;j<10;j++)
		{
			for(r=0;r<i;r++)
			{
				am[i][r][(r+j*10)%i]=min(am[i][r][(r+j*10)%i],i+j*10);
				am[i][r][(r+j)%i]=min(am[i][r][(r+j)%i],i*10+j);
			}
		}
		for(j=0;j<i;j++)
		{
			for(r=0;r<i;r++)
			{
				for(p=0;p<i;p++)
				{
					am[i][r][p]=min(am[i][r][p],am[i][r][j]+am[i][j][p]);
				}
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(k>=am[d][0][k%d])
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
}