#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int n;
long long dp[maxn][2];
char s[maxn];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	s[n]=s[0];
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='A')
		{
			dp[i+1][0]+=dp[i][0]+dp[i][1];
			if(s[i+1]=='B')dp[i+1][1]+=dp[i][1];
		}
		else
		{
			dp[i+1][0]+=dp[i][1];
			if(s[i+1]=='B')dp[i+1][1]+=dp[i][1];
			else dp[i+1][1]+=dp[i][0];
		}
	}
	long long ans=dp[n][0];
	memset(dp,0,sizeof(dp));
	dp[0][1]=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='A')
		{
			dp[i+1][0]+=dp[i][0]+dp[i][1];
			if(s[i+1]=='B')dp[i+1][1]+=dp[i][1];
		}
		else
		{
			dp[i+1][0]+=dp[i][1];
			if(s[i+1]=='B')dp[i+1][1]+=dp[i][1];
			else dp[i+1][1]+=dp[i][0];
		}
	}
	ans+=dp[n][1];
	printf("%I64d\n",ans);
	return 0;
}