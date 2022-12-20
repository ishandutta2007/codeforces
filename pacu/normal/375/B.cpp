#include <iostream>
using namespace std;

int cnt[5001];
char S[5001][5001];
int dp[5000];

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> S[i];
	int best = 0;
	int cur;
	for(int i=0;i<N;i++)
	{
		best += (S[i][0]=='1');
		dp[i] = (S[i][0]=='1');
	}
	for(int j=1;j<M;j++)
	{
		for(int i=0;i<N;i++)
		{
			if(S[i][j]=='1')
				dp[i]++;
			else
				dp[i] = 0;
			cnt[dp[i]]++;
		}
		cur = 0;
		for(int j=M;j>=0;j--)
		{
			cur += cnt[j];
			best = max(best,cur*j);
			cnt[j] = 0;
		}
	}
	cout << best << endl;
}