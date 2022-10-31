#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		vector<int> dp(n + 1);
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; j += i) {
				++dp[j];
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			dp[i] = (dp[i] + sum) % MOD;
			sum = (sum + dp[i]) % MOD;
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}