#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll Pow(ll x , ll y)
{
	ll ret = 1 , temp = x;
	while(y)
	{
		if(y & 1)
			ret = (ret * temp) % MOD;
		temp = (temp * temp) % MOD;
		y >>= 1;
	}
	return ret;
}

int n;
ll dp[200010];

int main()
{
	cin >> n;
	ll sum[2] = {0};
	dp[1] = dp[2] = 1;
	for(int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	ll x = 1;
	for(int i = 1; i <= n; i++)
		x = (x * 2) % MOD;
	cout << dp[n] * Pow(x , MOD -2 ) % MOD << endl;
	return 0;
}