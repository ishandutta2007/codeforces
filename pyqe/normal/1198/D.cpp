#include <bits/stdc++.h>

using namespace std;

long long n,ps[69][69],dp[69][69][69][69];
bool a[69][69];

long long bf(long long y1,long long x1,long long y2,long long x2)
{
	if(dp[y1][x1][y2][x2]==-1)
	{
		long long y=y2-y1+1,x=x2-x1+1,i;
		dp[y1][x1][y2][x2]=max(y,x);
		if(ps[y2][x2]-ps[y1-1][x2]-ps[y2][x1-1]+ps[y1-1][x1-1]==0)
		{
			dp[y1][x1][y2][x2]=0;
		}
		else if(ps[y2][x2]-ps[y1-1][x2]-ps[y2][x1-1]+ps[y1-1][x1-1]<y*x)
		{
			for(i=1;i<y;i++)
			{
				dp[y1][x1][y2][x2]=min(dp[y1][x1][y2][x2],bf(y1,x1,y1+i-1,x2)+bf(y1+i,x1,y2,x2));
			}
			for(i=1;i<x;i++)
			{
				dp[y1][x1][y2][x2]=min(dp[y1][x1][y2][x2],bf(y1,x1,y2,x1+i-1)+bf(y1,x1+i,y2,x2));
			}
		}
	}
	return dp[y1][x1][y2][x2];
}

int main()
{
	long long i,j,ii,jj;
	string s;
	
	for(i=1;i<=50;i++)
	{
		for(j=1;j<=50;j++)
		{
			for(ii=1;ii<=50;ii++)
			{
				for(jj=1;jj<=50;jj++)
				{
					dp[i][j][ii][jj]=-1;
				}
			}
		}
	}
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=n;j++)
		{
			if(s[j-1]=='#')
			{
				a[i][j]=1;
			}
			ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+a[i][j];
		}
	}
	printf("%lld\n",bf(1,1,n,n));
}