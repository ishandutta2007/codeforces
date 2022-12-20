#include <iostream>
using namespace std;

long long dp[50000][5];
long long t[50000][5];

int main()
{
	int M,N;
	cin >> M >> N;
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin >> t[i][j];
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
		{
			dp[i][j] = 0;
			if(i>0) dp[i][j] = max(dp[i][j],dp[i-1][j]);
			if(j>0) dp[i][j] = max(dp[i][j],dp[i][j-1]);
			dp[i][j] += t[i][j];
		}
	for(int i=0;i<M;i++)
		cout << dp[i][N-1] << " ";
	return 0;
}