#include <bits/stdc++.h>
using namespace std;
int w , b;
double dp[1001][1001];
int main()
{
	cin>>w>>b;
	for(int i = 1 ; i <= w ; ++i)
		dp[i][0] = 1.0;
	for(int i = 1 ; i <= w ; ++i)
	{
		for(int j = 1 ; j <= b ; ++j)
		{
			dp[i][j] = 1.0 * i / (i + j);
			if(j >= 2)
				dp[i][j] += dp[i - 1][j - 2] * i * 1.0 / (i + j - 2.0) * 1.0 * (j - 1.0) / (i + j) * 1.0 * j / (i + j - 1.0); //bw
			if(j >= 3)
				dp[i][j] += dp[i][j - 3] * 1.0 * j / (i + j + 0.0) * 1.0 * (j - 1.0) / (i + j - 1.0) * 1.0 * (j - 2.0) / (i + j - 2.0);
		}
	}
	cout<<fixed<<setprecision(9)<<dp[w][b];
}