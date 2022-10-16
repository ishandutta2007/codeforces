#include <bits/stdc++.h>

using namespace std;

long long a[10][10],n,m,dp[10][10];

int main()
{
	long long i,j,r,ln,z;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=1;i<ln;i++)
	{
		a[s[i-1]-'0'][s[i]-'0']++;
	}
	for(n=0;n<10;n++)
	{
		for(m=0;m<10;m++)
		{
			z=0;
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
				{
					dp[i][j]=1e18;
					if((i+n)%10==j)
					{
						dp[i][j]=1;
					}
					if((i+m)%10==j)
					{
						dp[i][j]=1;
					}
				}
			}
			for(r=0;r<10;r++)
			{
				for(i=0;i<10;i++)
				{
					for(j=0;j<10;j++)
					{
						dp[i][j]=min(dp[i][j],dp[i][r]+dp[r][j]);
					}
				}
			}
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
				{
					if(!a[i][j])
					{
						continue;
					}
					if(dp[i][j]>=1000000000000000000)
					{
						z=-1;
						break;
					}
					z+=a[i][j]*(dp[i][j]-1);
				}
				if(z==-1)
				{
					break;
				}
			}
			printf("%lld%c",z," \n"[m==9]);
		}
	}
}