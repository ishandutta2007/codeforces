#include <bits/stdc++.h>
using namespace std;
#define N 705
#define mod 1000000007
char s[N];
int match[N];
int tmp[N];
long long dp[N][N][3][3];
void getmatch(int len)
{
	int p = 0;
	for (int i = 0; i<len; i++)
	{
		if (s[i] == '(')
			tmp[p++] = i;
		else
		{
			match[i] = tmp[p - 1];
			match[tmp[p - 1]] = i;
			p--;
		}
	}
}
void dfs(int l, int r)
{
	if (l + 1 == r)
	{
		dp[l][r][0][1] = 1;
		dp[l][r][1][0] = 1;
		dp[l][r][0][2] = 1;
		dp[l][r][2][0] = 1;
	}
	else if (match[l] == r)
	{
		dfs(l + 1, r - 1);
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				if (j != 1)
				dp[l][r][0][1] = (dp[l][r][0][1] + dp[l + 1][r - 1][i][j]) % mod;
				if (i != 1)
					dp[l][r][1][0] = (dp[l][r][1][0] + dp[l + 1][r - 1][i][j]) % mod;
				if (j != 2)
					dp[l][r][0][2] = (dp[l][r][0][2] + dp[l + 1][r - 1][i][j]) % mod;
				if (i != 2)
					dp[l][r][2][0] = (dp[l][r][2][0] + dp[l + 1][r - 1][i][j]) % mod;
			}
		}
	}
	else
	{
		int p = match[l];
		dfs(l, p);
		dfs(p + 1, r);
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				for (int k = 0; k<3; k++)
				{
					for (int q = 0; q<3; q++)
					{
						if (k!=q||(!k&&!q))
							dp[l][r][i][j] = (dp[l][r][i][j] + (dp[l][p][i][k] * dp[p + 1][r][q][j]) % mod) % mod;
					}
				}
			}
		}
	}
}
 
int main()
{
	scanf("%s", s);
	int len = strlen(s);
	getmatch(len);
	memset(dp, 0, sizeof(dp));
	dfs(0, len - 1);
	long long ans = 0;
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			ans = (ans + dp[0][len - 1][i][j]) % mod;
		}
	}
	if (len>1000) cout<<0;
	cout<<ans;
}