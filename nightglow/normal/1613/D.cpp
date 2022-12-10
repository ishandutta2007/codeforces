#include <bits/stdc++.h>

#define N 500005
#define Mo 998244353

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int dp[N][2], x, n;

void Main()
{
	scanf("%d", &n); int ans = 0;
	for (int i = 0; i <= n; ++i) dp[i][0] = dp[i][1] = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &x);
		//last = x + 1
		dp[x + 1][0] = dp[x + 1][0] * 2 % Mo;
		dp[x + 1][1] = dp[x + 1][1] * 2 % Mo;
		//last = x
		(dp[x + 1][0] += dp[x][0]) %= Mo;
		//last = x - 1
		(dp[x - 1][1] += dp[x - 1][1]) %= Mo; 
		(dp[x - 1][1] += dp[x - 1][0]) %= Mo;
	}
	for (int i = 0; i <= n; ++i) (ans += dp[i][0]) %= Mo,
								 (ans += dp[i][1]) %= Mo;
	printf("%d\n", (ans + Mo - 1) % Mo);
}

int main()
{
	int T; scanf("%d", &T);
	for (;T--;) Main();
}