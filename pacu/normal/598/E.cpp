#include <iostream>
using namespace std;

long long dp[31][31][51];

int main()
{
	for(int i=0;i<=30;i++)
		for(int j=0;j<=30;j++)
			dp[i][j][0] = 0;
	for(int j=0;j<=30;j++)
		for(int k=1;k<=50;k++)
			dp[0][j][k] = 1000000000;
	for(int i=0;i<=30;i++)
		for(int k=1;k<=50;k++)
			dp[i][0][k] = 1000000000;
	for(int i=1;i<=30;i++)
		for(int j=1;j<=30;j++)
			for(int k=1;k<=50;k++)
			{
				if(i>j) dp[i][j][k] = dp[j][i][k];
				else if(k==i*j) dp[i][j][k] = 0;
				else
				{
					dp[i][j][k] = 1000000000;
					for(int c=1;c<i;c++)
						for(int p=0;p<=k;p++)
							dp[i][j][k] = min(dp[i][j][k],dp[c][j][p]+dp[i-c][j][k-p]+j*j);
					for(int c=1;c<j;c++)
						for(int p=0;p<=k;p++)
							dp[i][j][k] = min(dp[i][j][k],dp[i][c][p]+dp[i][j-c][k-p]+i*i);
				}
			}
	int t,n,m,k;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n >> m >> k;
		cout << dp[n][m][k] << '\n';
	}
}