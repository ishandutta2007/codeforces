#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int n , a[200010];
long long dp[200010][3];

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++)
		{
			dp[i + 1][0] = dp[i][0] + (i & 1 ? 0 : a[i]);
			if(i + 2 <= n)
				dp[i + 2][1] = max(dp[i][0] , dp[i][1]) + (i & 1 ? a[i] : a[i + 1]);
			dp[i + 1][2] = max(dp[i][0] , max(dp[i][1] , dp[i][2])) + (i & 1 ? 0 : a[i]);
		}
		cout << max(dp[n][0] , max(dp[n][1] , dp[n][2])) << endl;
	}
	return 0;
}