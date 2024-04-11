#include <iostream>
using namespace std;

long long dp[5001][5000];	//[index][number of ranges]

long long A[5000];
long long cnt[5001];
int main()
{
	int N,rSize,K;
	cin >> N >> rSize >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	cnt[0] = 0;
	for(int i=0;i<N;i++)
		cnt[i+1] = cnt[i]+A[i];
	for(int k=0;k<=K;k++)
		dp[0][k] = 0;
	long long best = 0;
	for(int i=1;i<=N;i++)
	{
		for(int k=1;k<=K;k++)
		{
			dp[i][k] = dp[i-1][k];
			if(i>=rSize)
				dp[i][k] = max(dp[i][k],dp[i-rSize][k-1]+cnt[i]-cnt[i-rSize]);
			best = max(best,dp[i][k]);
		}
	}
	cout << best << endl;
}