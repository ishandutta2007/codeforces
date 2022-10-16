#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],z[4];
bitset<8> dp[100069][4];

int main()
{
	long long i,j,ii,jj;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	dp[0][0][0]=1;
	for(i=1;i<=n;i++)
	{
		dp[i][0][0]=1;
		for(ii=1;ii<=3;ii++)
		{
			for(j=0;j<8;j++)
			{
				jj=(j+64-a[i]*(1<<3-ii))%8;
				dp[i][ii][j]=dp[i-1][ii][j]|dp[i-1][ii-1][jj]|dp[i-1][0][jj];
			}
		}
	}
	if(!dp[n][3][0])
	{
		printf("NO\n");
		return 0;
	}
	ii=3;
	j=0;
	for(i=n;i>0;i--)
	{
		if(!dp[i-1][ii][j])
		{
			z[ii]=a[i];
			j=(j+64-a[i]*(1<<3-ii))%8;
			ii--;
			if(!dp[i-1][ii][j])
			{
				break;
			}
		}
	}
	printf("YES\n");
	for(i=ii+1;i<=3;i++)
	{
		printf("%lld",z[i]);
	}
	printf("\n");
}