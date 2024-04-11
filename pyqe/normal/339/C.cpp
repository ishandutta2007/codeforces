#include <bits/stdc++.h>

using namespace std;

long long n,sm[1069][11],sq[1069];
bitset<11> a,dp[1069][11];

int main()
{
	long long i,j,r,e=0,ls=0;
	string s;
	
	cin>>s;
	for(i=1;i<=10;i++)
	{
		a[i]=s[i-1]-'0';
	}
	scanf("%lld",&n);
	sm[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=10;j++)
		{
			for(r=j;r<=10;r++)
			{
				dp[i][j][r]=!!(sm[i-1][r-j]-dp[i-1][r-j][r])*a[r];
				sm[i][j]+=dp[i][j][r];
			}
		}
	}
	for(i=1;i<=10;i++)
	{
		if(sm[n][i])
		{
			e=i;
		}
	}
	if(!e)
	{
		printf("NO\n");
		return 0;
	}
	for(i=n;i;i--)
	{
		for(j=1;j<=10;j++)
		{
			if(j!=ls&&dp[i][e][j])
			{
				sq[i]=j;
				e=j-e;
				ls=j;
				break;
			}
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}