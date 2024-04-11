#include <iostream>
#include <string>
using namespace std;

int N;
string s;

int dp[2][3][100000];

int main()
{
	cin >> N >> s;
	if(s[0]=='0')
	{
		dp[0][0][0] = 1;
		dp[1][0][0] = 0;
		dp[0][1][0] = dp[0][2][0] = dp[1][1][0] = dp[1][2][0] = 1;
	}
	else
	{
		dp[0][0][0] = 0;
		dp[1][0][0] = 1;
		dp[0][1][0] = dp[0][2][0] = dp[1][1][0] = dp[1][2][0] = 1;		
	}
	for(int i=1;i<N;i++)
	{
		int c = s[i]-'0';
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<3;k++)
			{
				dp[j][k][i] = dp[j][k][i-1];
				if(j==c) dp[j][k][i] = max(dp[j][k][i],dp[j^1][k][i-1]+1);
			}
		}
		for(int k=1;k<3;k++)
			dp[c^1][k][i] = max(dp[c^1][k][i],dp[c][k-1][i]);
	}
	int ans = 0;
	for(int j=0;j<2;j++)
		for(int k=0;k<3;k++)
			ans = max(ans,dp[j][k][N-1]);
	cout << ans << '\n';
}