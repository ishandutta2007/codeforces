#include <bits/stdc++.h>

using namespace std;

long long n,a[569],dp[569][569];

long long bf(long long x,long long y)
{
	if(x>y+1)
	{
		return -1e18;
	}
	if(dp[x][y]==-1)
	{
		long long i;
		
		dp[x][y]=0;
		dp[x][y]=max(dp[x][y],bf(x+1,y-1)+(a[x]==a[y]));
		for(i=x;i<=y;i++)
		{
			dp[x][y]=max(dp[x][y],bf(x,i)+bf(i,y));
		}
	}
	return dp[x][y];
}

int main()
{
	long long i,j;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]=-1;
		}
	}
	printf("%lld\n",n-bf(1,n));
}