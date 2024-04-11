#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

int dp[80][80][80];

int N,K,M;
int dif[80][80];

int main()
{
	cin >> N >> K >> M;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dif[i][j] = INF;
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		a--,b--;
		dif[a][b] = min(dif[a][b],c);
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int k=0;k<K;k++)
				dp[i][j][k] = INF;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dp[i][j][0] = 0;
	int v;
	for(int k=1;k<K;k++)
	{
		for(int i=0;i<N;i++)
			for(int j=i+k;j<N;j++)
			{
				v = INF;
				for(int l=i+1;l<=j;l++)
					v = min(v,dif[i][l]+min(dp[l][i+1][k-1],dp[l][j][k-1]));
				dp[i][j][k] = v;
			}
		for(int i=0;i<N;i++)
			for(int j=i-k;j>=0;j--)
			{
				v = INF;
				for(int l=i-1;l>=j;l--)
					v = min(v,dif[i][l]+min(dp[l][i-1][k-1],dp[l][j][k-1]));
				dp[i][j][k] = v;
			}
	}
	int ans = INF;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			ans = min(ans,dp[i][j][K-1]);
	if(ans==INF) ans = -1;
	cout << ans << '\n';
}