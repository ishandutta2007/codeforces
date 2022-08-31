#include <bits/stdc++.h>
using namespace std;

int n;

long long c;
long long p[10007];
long long s[10007];

long long inf=(long long)1000*1000*1000*1000*1000;

int g;
long long dp[2][10007];

long long wyn=inf;

int main()
{
	scanf("%d%lld", &n, &c);
	for (int i=1; i<=n; i++)
		scanf("%lld", &p[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &s[i]);
	for (int i=1; i<=n; i++)
		dp[0][i]=inf;
	for (int i=1; i<=n; i++)
	{
		int g=(i&1);
		for (int j=0; j<=n; j++)
			dp[g][j]=inf;
		for (int j=0; j<=i-1; j++)
		{
			int l=i-1-j;
			
			//do pierwszego
			dp[g][j+1]=min(dp[g][j+1], dp[g^1][j]+s[i]);
			//do drugiego
			dp[g][j]=min(dp[g][j], dp[g^1][j]+p[i]+c*j);
		}
	}
	for (int i=0; i<=n; i++)
		wyn=min(wyn, dp[n&1][i]);
	printf("%lld\n", wyn);
	return 0;
}