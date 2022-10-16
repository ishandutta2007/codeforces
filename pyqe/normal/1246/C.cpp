#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dp[2][2069][2069],aa[2][2069][2069],ps[2][2069][2069],dv=1e9+7;
bitset<2069> a[2069];

int main()
{
	long long i,j,ii,z;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=n;i>0;i--)
	{
		cin>>s;
		for(j=m;j>0;j--)
		{
			a[i][j]=s[m-j]=='R';
		}
	}
	if(n==1&&m==1)
	{
		if(a[1][1])
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			aa[0][i][j]=aa[0][i-1][j]+a[i][j];
			aa[1][i][j]=aa[1][i][j-1]+a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i==1&&j==1)
			{
				dp[0][i][j]=1;
				dp[1][i][j]=1;
			}
			else
			{
				dp[0][i][j]=(ps[1][i][j-1]+dv-ps[1][i][aa[1][i][j-1]])%dv;
				dp[1][i][j]=(ps[0][i-1][j]+dv-ps[0][aa[0][i-1][j]][j])%dv;
			}
			ps[0][i][j]=(ps[0][i-1][j]+dp[0][i][j])%dv;
			ps[1][i][j]=(ps[1][i][j-1]+dp[1][i][j])%dv;
		}
	}
	printf("%lld\n",(dp[0][n][m]+dp[1][n][m])%dv);
}