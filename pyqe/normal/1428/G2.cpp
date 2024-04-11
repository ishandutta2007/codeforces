#include <bits/stdc++.h>

using namespace std;

const long long d=6,inf=1e18;
long long n,a[d],p10[d+1],dp[2][1000069],sp[3][19][333369],lg2[1000069];

inline long long spqr(long long xx,long long lh,long long rh)
{
	long long e;
	
	if(lh>rh)
	{
		return -inf;
	}
	e=lg2[rh-lh+1];
	return max(sp[xx][e][lh],sp[xx][e][rh-(1ll<<e)+1]);
}

int main()
{
	long long t,rr,i,j,r,ii,k,sz;
	
	scanf("%lld",&n);
	for(i=d-1;i>=0;i--)
	{
		scanf("%lld",a+i);
	}
	p10[0]=1;
	for(i=1;i<=d;i++)
	{
		p10[i]=p10[i-1]*10;
	}
	lg2[1]=0;
	for(i=2;i<=p10[d];i++)
	{
		lg2[i]=lg2[i/2]+1;
	}
	for(i=0;i<d;i++)
	{
		for(j=p10[i+1]-1;j>=0;j--)
		{
			if(j%10==0)
			{
				dp[0][j]=dp[0][j/10];
			}
			else
			{
				dp[0][j]=-inf;
			}
		}
		for(ii=0;ii<3;ii++)
		{
			sz=(p10[i+1]-1-ii)/3;
			for(j=0;j<=sz;j++)
			{
				sp[ii][0][j]=dp[0][j*3+ii]-a[i]*j;
			}
			for(j=1;1ll<<j<=sz+1;j++)
			{
				for(r=0;r<=sz-(1ll<<j)+1;r++)
				{
					sp[ii][j][r]=max(sp[ii][j-1][r],sp[ii][j-1][r+(1ll<<j-1)]);
				}
			}
		}
		for(j=0;j<p10[i+1];j++)
		{
			dp[1][j]=-inf;
			for(ii=0;ii<=min(2ll,j);ii++)
			{
				dp[1][j]=max(dp[1][j],spqr((j+3-ii)%3,max((j-ii)/3-((n-1)*3-1),0ll),(j-ii)/3)+a[i]*((j-ii)/3));
			}
			for(r=(n-1)*9;r<=n*9;r++)
			{
				if(r<=j)
				{
					dp[1][j]=max(dp[1][j],dp[0][j-r]+a[i]*((n-1)*3+(r-(n-1)*9)/3*(r%3==0)));
				}
			}
		}
		for(j=0;j<p10[i+1];j++)
		{
			dp[0][j]=dp[1][j];
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		printf("%lld\n",dp[0][k]);
	}
}