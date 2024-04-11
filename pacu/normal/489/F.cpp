#include <iostream>
#include <string>
using namespace std;

long long dp[501][501];
int A[500][500];
int main()
{
	for(int i=0;i<=500;i++)
		for(int j=0;j<=500;j++)
			dp[i][j] = 0;
	int N,M,MOD;
	cin >> N >> M >> MOD;
	string s;
	for(int i=0;i<M;i++)
	{
		cin >> s;
		for(int j=0;j<N;j++)
			A[i][j] = s[j]-'0';
	}
	dp[0][0] = 1;
	for(int sm=2;sm<=1000;sm+=2)	//total number of 1s left
	{
		for(int a=0;(a<=sm) && (a<=500);a++)	//number of columns with 1 one left
		{
			int b = sm-a;
			if(b%2) continue;
			b /= 2;

			dp[a][b] = 0;
			if(a>=2)
			{
				dp[a][b] += dp[a-2][b]*(a*(a-1))/2;
				dp[a][b] %= MOD;
			}
			if(b>=1)
			{
				dp[a][b] += dp[a][b-1]*a*b;
				dp[a][b] %= MOD;
			}
			if(b>=2)
			{
				dp[a][b] += dp[a+2][b-2]*(b*(b-1))/2;
				dp[a][b] %= MOD;
			}
		}
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i=0;i<N;i++)
	{
		int tot = 0;
		for(int j=0;j<M;j++)
			tot += A[j][i];
		if(tot==1)
			cnt1++;
		if(tot==0)
			cnt2++;
	}
	cout << dp[cnt1][cnt2] << endl;
}