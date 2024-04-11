#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int N,L,K;
double dp[2][201][401];	//[cur][j][k] is probability of winning j tours and having k-200 excess capacity
int p[200];
int b[200];

int main()
{
	cin >> N >> L >> K;
	for(int i=0;i<N;i++)
		cin >> p[i];
	for(int i=0;i<N;i++)
		cin >> b[i];
	int cur = 0;
	int prev = 1;
	dp[prev][0][K+200] = 1.0;
	for(int i=0;i<N;i++,swap(cur,prev))
	{
		for(int j=0;j<=i;j++)
			for(int k=0;k<=400;k++)
				dp[cur][j][k] = dp[prev][j][k]*(1.0 - p[i]/100.0);
		for(int j=0;j<=i;j++)
			for(int k=max(0,-b[i]);k<=400;k++)
				dp[cur][j+1][min(400,k+b[i])] += dp[prev][j][k]*(p[i]/100.0);
	}
	double ans = 0.0;
	for(int j=L;j<=N;j++)
		for(int k=200;k<=400;k++)
			ans += dp[prev][j][k];
	cout << setprecision(20) << ans << '\n';
}