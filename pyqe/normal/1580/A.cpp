#include <bits/stdc++.h>

using namespace std;

const long long d=5,d2=4,inf=1e18;
long long n,m,ps[469][469],dp[469];

long long val(long long y,long long x,long long y2,long long x2)
{
	return ps[y2][x2]-ps[y-1][x2]-ps[y2][x-1]+ps[y-1][x-1];
}

long long val2(long long xx,long long y,long long x,long long y2,long long x2)
{
	if(xx)
	{
		return val(y,x,y2,x2);
	}
	else
	{
		return (y2-y+1)*(x2-x+1)-val(y,x,y2,x2);
	}
}

int main()
{
	long long t,rr,i,j,r,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+(ch-'0');
			}
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			for(j=i+d-1;j<=n;j++)
			{
				dp[0]=inf;
				for(r=1;r<=m;r++)
				{
					dp[r]=min(dp[r-1],val2(0,i+1,r,j-1,r)-val2(0,i,1,i,r)-val2(1,i+1,1,j-1,r)-val2(0,j,1,j,r));
					if(r>=d2)
					{
						z=min(z,val2(0,i+1,r,j-1,r)+val2(0,i,1,i,r-1)+val2(1,i+1,1,j-1,r-1)+val2(0,j,1,j,r-1)+dp[r-d2+1]);
					}
				}
			}
		}
		printf("%lld\n",z);
	}
}