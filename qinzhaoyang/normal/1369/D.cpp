#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;
long long dp[2000010] , t , n;

int main()
{
	for(int i = 3; i <= 2000000; i++)
		dp[i] = (2 * dp[i - 2] + dp[i - 1] + 4 * (i % 3 == 0)) % MOD;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}