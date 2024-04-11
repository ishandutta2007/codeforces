#include <bits/stdc++.h>

using namespace std;

long long n,dp[11][21];

int main()
{
	long long i,j,tg=10;
	double z;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		if(s[i]=='+')
		{
			tg++;
		}
		else if(s[i]=='-')
		{
			tg--;
		}
	}
	dp[0][10]=1;
	cin>>s;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=20;j++)
		{
			if(dp[i][j])
			{
				if(s[i]=='+')
				{
					dp[i+1][j+1]+=dp[i][j]*2;
				}
				else if(s[i]=='-')
				{
					dp[i+1][j-1]+=dp[i][j]*2;
				}
				else if(s[i]=='?')
				{
					dp[i+1][j-1]+=dp[i][j];
					dp[i+1][j+1]+=dp[i][j];
				}
			}
		}
	}
	z=(double)dp[n][tg]/(1<<n);
	printf("%.12lf\n",z);
}