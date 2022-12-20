#include <iostream>
using namespace std;

int dp[100001];
int sm[100001];

int main()
{
	int t,k;
	cin >> t >> k;
	dp[0] = 1;
	sm[0] = dp[0];
	for(int i=1;i<=100000;i++)
	{
		dp[i] = dp[i-1];
		if(i >= k)
			dp[i] += dp[i-k];
		dp[i] %= 1000000007;
		sm[i] = sm[i-1] + dp[i];
		sm[i] %= 1000000007;
	}
	for(int i=0;i<t;i++)
	{
		int a,b;
		cin >> a >> b;
		int ans = sm[b]-sm[a-1];
		ans %= 1000000007;
		if(ans < 0)
			ans += 1000000007;
		cout << ans << endl;
	}
}