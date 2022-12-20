#include <iostream>
#include <iomanip>
using namespace std;

long double dp[51][51][51];	//[k][n][x meters]

int main()
{
	int N,P;
	int A[50];
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	cin >> P;
	for(int k=0;k<=N;k++)
		for(int n=0;n<=N;n++)
			dp[k][n][0] = 0;
	for(int k=0;k<=N;k++)
		for(int x=0;x<=P;x++)
			dp[k][0][x] = 0;
	for(int n=0;n<=N;n++)
		for(int x=0;x<=P;x++)
			dp[0][n][x] = 1;
	for(int x=1;x<=P;x++)
		for(int n=1;n<=N;n++)
			for(int k=1;k<=n;k++)
			{
				dp[k][n][x] = 0;
				if(x >= A[n-1])
				{
					dp[k][n][x] += (((long double)k)/((long double)n))*dp[k-1][n-1][x-A[n-1]];
				}
				if(k <= (n-1))
					dp[k][n][x] += (((long double)(n-k))/((long double)n))*dp[k][n-1][x];

			}
	long double ans = 0;
	long double prev = 0;
	for(int k=N;k>=0;k--)
	{
		ans += (dp[k][N][P]-prev)*k;
		prev = dp[k][N][P];
	}
	cout << setprecision(10) << ans << endl;
}