#include <bits/stdc++.h>

using namespace std;

long long n[2],dp[269][269][469];
bitset<269> a[2];

long long bf(long long i,long long j,long long r)
{
	if(r<0||r>n[0]+n[1])
	{
		return 1e18;
	}
	if(dp[i][j][r]==-1)
	{
		if(i==n[0]+1&&j==n[1]+1)
		{
			dp[i][j][r]=r;
		}
		else
		{
			dp[i][j][r]=bf(i,j,r+1)+1;
			if(i<=n[0]&&j<=n[1]&&a[0][i]==a[1][j])
			{
				dp[i][j][r]=min(dp[i][j][r],bf(i+1,j+1,r+a[0][i]*2-1)+1);
			}
			else
			{
				if(i<=n[0])
				{
					dp[i][j][r]=min(dp[i][j][r],bf(i+1,j,r+a[0][i]*2-1)+1);
				}
				if(j<=n[1])
				{
					dp[i][j][r]=min(dp[i][j][r],bf(i,j+1,r+a[1][j]*2-1)+1);
				}
			}
		}
	}
	return dp[i][j][r];
}

int main()
{
	long long ii,i,j,r;
	string s;
	
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		n[ii]=s.length();
		for(i=1;i<=n[ii];i++)
		{
			a[ii][i]=s[i-1]=='(';
		}
	}
	for(i=1;i<=n[0]+1;i++)
	{
		for(j=1;j<=n[1]+1;j++)
		{
			for(r=0;r<=n[0]+n[1];r++)
			{
				dp[i][j][r]=-1;
			}
		}
	}
	for(i=1,j=1,r=0;i<=n[0]||j<=n[1];)
	{
		if(bf(i,j,r)==bf(i,j,r+1)+1)
		{
			printf("(");
			r++;
		}
		else if(i<=n[0]&&j<=n[1]&&a[0][i]==a[1][j]&&bf(i,j,r)==bf(i+1,j+1,r+a[0][i]*2-1)+1)
		{
			printf("%c",")("[a[0][i]]);
			r+=a[0][i]*2-1;
			i++;
			j++;
		}
		else if(i<=n[0]&&bf(i,j,r)==bf(i+1,j,r+a[0][i]*2-1)+1)
		{
			printf("%c",")("[a[0][i]]);
			r+=a[0][i]*2-1;
			i++;
		}
		else if(j<=n[1]&&bf(i,j,r)==bf(i,j+1,r+a[1][j]*2-1)+1)
		{
			printf("%c",")("[a[1][j]]);
			r+=a[1][j]*2-1;
			j++;
		}
	}
	for(i=0;i<r;i++)
	{
		printf(")");
	}
	printf("\n");
}