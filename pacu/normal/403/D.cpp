#include <iostream>
using namespace std;
#define MOD 1000000007


long long dp[2000][2000];
long long sm[2000][2000];
long long fact[2000];
long long dp0[2000][2000];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	for(int m=0;m<2000;m++)
		dp[m][0] = 1, sm[m][0] = m+1;
	for(int k=1;k<2000;k++)
	{
		dp[0][k] = sm[0][k] = 0;
		dp0[0][k] = (k==1);
		for(int m=1;m<2000;m++)
		{
			dp[m][k] = 0;
			if(k==1)
			{
				if(m >= k) dp[m][k] += sm[m-k][k-1];
			}
			else
			{
				if(m > k) dp[m][k] += sm[m-k-1][k-1];
			}
			if(m >= k) dp[m][k] += dp[m-k][k];
			sm[m][k] = sm[m-1][k] + dp[m][k];
			
			dp0[m][k] = dp[m][k] + sm[m-1][k-1];
			if(k==1) dp0[m][k]++;
//			cout << k << ' ' << m << ": " << dp0[m][k] << '\n';
			sm[m][k] %= MOD;
			dp[m][k] %= MOD;
			dp0[m][k] %= MOD;
		}
	}
	fact[1] = 1;
	for(int i=2;i<2000;i++)
		fact[i] = (fact[i-1]*i)%MOD;
	int t;
	cin >> t;
	int n,k;
	for(int i=0;i<t;i++)
	{
		cin >> n >> k;
		cout << (dp0[n-1][k]*fact[k])%MOD << '\n';
	}
}