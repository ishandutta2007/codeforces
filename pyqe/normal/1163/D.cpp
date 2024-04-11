#include <bits/stdc++.h>

using namespace std;

long long n,aa[1069],nn[2],a[2][69],faf[2][69],pr[2][50][26],dp[1001][50][50];

int main()
{
	long long i,j,r,ii,k,p[2],tg[2],z=-1e18;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		aa[i]=s[i-1]-'a';
		if(aa[i]=='*'-'a')
		{
			aa[i]=26;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		nn[ii]=s.length();
		for(i=1;i<=nn[ii];i++)
		{
			a[ii][i]=s[i-1]-'a';
		}
		faf[ii][0]=-1;
		for(i=1;i<=nn[ii];i++)
		{
			for(j=faf[ii][i-1];j+1&&a[ii][j+1]!=a[ii][i];j=faf[ii][j]);
			faf[ii][i]=j+1;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<nn[ii];i++)
		{
			for(j=0;j<26;j++)
			{
				for(r=i;r+1&&a[ii][r+1]!=j;r=faf[ii][r]);
				pr[ii][i][j]=r+1;
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		for(p[0]=0;p[0]<nn[0];p[0]++)
		{
			for(p[1]=0;p[1]<nn[1];p[1]++)
			{
				dp[i][p[0]][p[1]]=-1e18;
			}
		}
	}
	dp[0][0][0]=0;
	for(i=0;i<n;i++)
	{
		for(j=aa[i+1]%26;j<=min(aa[i+1],25ll);j++)
		{
			for(p[0]=0;p[0]<nn[0];p[0]++)
			{
				for(p[1]=0;p[1]<nn[1];p[1]++)
				{
					k=dp[i][p[0]][p[1]];
					for(ii=0;ii<2;ii++)
					{
						tg[ii]=pr[ii][p[ii]][j];
						if(tg[ii]==nn[ii])
						{
							k+=!ii*2-1;
							tg[ii]=faf[ii][tg[ii]];
						}
					}
					dp[i+1][tg[0]][tg[1]]=max(dp[i+1][tg[0]][tg[1]],k);
				}
			}
		}
	}
	for(p[0]=0;p[0]<nn[0];p[0]++)
	{
		for(p[1]=0;p[1]<nn[1];p[1]++)
		{
			z=max(z,dp[n][p[0]][p[1]]);
		}
	}
	printf("%lld\n",z);
}