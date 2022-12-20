#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100000];
int dp[100000][300];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int k=1;k<300;k++)
	{
		for(int i=N-1;i>=0;i--)
		{
			if(i + A[i] + k >= N) dp[i][k] = 1;
			else dp[i][k] = 1 + dp[i+A[i]+k][k];
		}
	}
	int Q,p,k;
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		cin >> p >> k;
		p--;
		if(k < 300) cout << dp[p][k] << '\n';
		else
		{
			int ans = 0;
			while(p < N)
			{
				ans++;
				p = p + A[p] + k;
			}
			cout << ans << '\n';
		}
	}
}