#include <bits/stdc++.h>

using namespace std;

long long n,m,aa[469],a[469],dp[469][469];

int main()
{
	long long t,rr,i,j,r;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			aa[i]=s[i-1]-'a';
		}
		cin>>s;
		m=s.length();
		for(i=1;i<=m;i++)
		{
			a[i]=s[i-1]-'a';
		}
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=i;j++)
			{
				dp[i][j]=-1e18*!!j;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				for(r=j;r+1;r--)
				{
					if(dp[j][r]>=0&&dp[j][r]<m-j&&a[j+dp[j][r]+1]==aa[i])
					{
						dp[j][r]++;
					}
					if(r&&a[r]==aa[i])
					{
						dp[j][r]=max(dp[j][r],dp[j][r-1]);
					}
				}
			}
		}
		for(i=0;i<=m;i++)
		{
			if(dp[i][i]==m-i)
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}