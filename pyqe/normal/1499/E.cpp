#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][1069],dp[1069][1069][28],dv=998244353;

long long bf(long long x,long long y,long long w)
{
	if(dp[x][y][w]==-1)
	{
		if(w<=26)
		{
			dp[x][y][w]=w==26;
			if(x&&a[0][x]==w)
			{
				dp[x][y][w]=(dp[x][y][w]+bf(x-1,y,27)+dv-bf(x-1,y,w))%dv;
			}
			if(y&&a[1][y]==w)
			{
				dp[x][y][w]=(dp[x][y][w]+bf(x,y-1,27)+dv-bf(x,y-1,w))%dv;
			}
		}
		else
		{
			long long i;
			
			dp[x][y][w]=0;
			for(i=0;i<=26;i++)
			{
				dp[x][y][w]=(dp[x][y][w]+bf(x,y,i))%dv;
			}
		}
	}
	return dp[x][y][w];
}

int main()
{
	long long i,j,r,ii,l,z=0;
	string s;
	
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		n[ii]=s.length();
		for(i=1;i<=n[ii];i++)
		{
			a[ii][i]=s[i-1]-'a';
		}
	}
	for(i=0;i<=n[0];i++)
	{
		for(j=0;j<=n[1];j++)
		{
			for(r=0;r<=27;r++)
			{
				dp[i][j][r]=-1;
			}
		}
	}
	for(i=0;i<=n[0];i++)
	{
		for(j=0;j<=n[1];j++)
		{
			z=(z+bf(i,j,27))%dv;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		l=0;
		for(i=0;i<=n[ii];i++)
		{
			if(i>=2&&a[ii][i]==a[ii][i-1])
			{
				l=i-1;
			}
			z=(z+dv-(i-l+1)*(n[!ii]+1)%dv)%dv;
		}
	}
	z=(z+(n[0]+1)*(n[1]+1))%dv;
	printf("%lld\n",z);
}