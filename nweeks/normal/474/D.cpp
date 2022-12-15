#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100001;

long long dp[MAXN];
int test_cases, K;

void precompute(void)
{
	dp[0] = 1;
	for (int i(1); i < MAXN; ++i)
		dp[i] = (dp[i-1] + (i >= K ? dp[i-K] : 0))%((int)1e9+7);
	for (int i(1); i < MAXN; ++i)
		dp[i] += dp[i-1];
}

int main(void)
{
	cin >> test_cases >> K;

	precompute();

	while (test_cases--)
	{
		int a, b;
		cin >> a >> b;
		cout << ((int)1e9+7 + dp[b] - dp[a-1]) % ((int)1e9+7) << endl;
	}
}