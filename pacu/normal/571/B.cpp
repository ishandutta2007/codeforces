#include <iostream>
#include <algorithm>
using namespace std;
#define INF 10000000000000000LL

int N,K;
long long A[300000];
int X;

long long dp[5001][5001];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);

	if(K == 1)
	{
		cout << A[N-1] - A[0] << '\n';
		return 0;
	}
	
	X = N/K;
	if(X*K < N)
		X++;
	int n;
	for(int i=0;i<=5000;i++)
		for(int j=0;j<=5000;j++)
		{
			n = i*X + j*(X-1);
			if(n > N) continue;
			if(i == 0 && j == 0) dp[i][j] = 0;
			else
			{
				dp[i][j] = INF;
				if(i > 0) dp[i][j] = min(dp[i][j],A[n-1] - A[n-X] + dp[i-1][j]);
				if(j > 0) dp[i][j] = min(dp[i][j],A[n-1] - A[n+1-X] + dp[i][j-1]);
			}
		}
	if(X*K == N) cout << dp[K][0] << '\n';
	else cout << dp[N%K][K-(N%K)] << '\n';
	return 0;
}