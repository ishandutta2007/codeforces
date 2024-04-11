#include <iostream>
using namespace std;

int A[5][1000];

int main()
{
	int N,K;
	cin >> N >> K;
	for(int k=0;k<K;k++)
		for(int i=0;i<N;i++)
		{
			cin >> A[k][i];
			A[k][i]--;
		}
	int dp[1000];
	int cnt[1000];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cnt[j] = 0;
		int cur = A[0][i];
		for(int k=0;k<K;k++)
			for(int j=0;A[k][j]!=cur;j++)
			{
				cnt[A[k][j]]++;
			}
		dp[cur] = 1;
		for(int j=0;j<N;j++)
			if(cnt[j]==K)
				dp[cur] = max(dp[cur],1+dp[j]);
	}
	int mx = 0;
	for(int i=0;i<N;i++)
		mx = max(mx,dp[i]);
	cout << mx << endl;
}