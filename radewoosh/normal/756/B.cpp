#include <bits/stdc++.h>
using namespace std;

int n;

int tab[1000007];
int dp[1000007];

int x1=1, x2=1;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		tab[i]++;
	}
	for (int i=1; i<=n; i++)
	{
		dp[i]=dp[i-1]+20;
		
		while(x1<i && tab[x1]+90<=tab[i])
			x1++;
		while(x2<i && tab[x2]+1440<=tab[i])
			x2++;
		dp[i]=min(dp[i], dp[x1-1]+50);
		dp[i]=min(dp[i], dp[x2-1]+120);
		printf("%d\n", dp[i]-dp[i-1]);
	}
	return 0;
}