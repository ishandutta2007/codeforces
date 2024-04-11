#include <bits/stdc++.h>
using namespace std;

int n;

char wcz[5007];
int tab[5007];

long long dp[5007][30];
long long dod[5007];

long long mod=1000000007;

long long s;

int main()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=wcz[i]-'a'+1;
	dp[0][0]=1;
	for (int i=1; i<=n; i++)
	{
		s=0;
		for (int j=1; j<=n; j++)
		{
			s+=dp[j-1][0]-dp[j-1][tab[i]]+mod;
			while (s>=mod)
				s-=mod;
			dod[j]=s;
		}
		for (int j=1; j<=n; j++)
		{
			dp[j][0]+=mod-dp[j][tab[i]];
			while (dp[j][0]>=mod)
				dp[j][0]-=mod;
				
			dp[j][tab[i]]=dod[j];
			
			dp[j][0]+=dp[j][tab[i]];
			while (dp[j][0]>=mod)
				dp[j][0]-=mod;
		}
	}
	printf("%lld\n", dp[n][0]);
	return 0;
}