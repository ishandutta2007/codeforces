#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

const double pi = 3.14159265358979323846;

long long maxd = 1, bound = 1e5;
int inf = int(1e9) + 7;

int C(int n, int k)
{
	static vector<vector<int>> dp(500, vector<int>(500, -1));

	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	if (dp[n][k] == -1)
		dp[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % inf;

	return dp[n][k];
}

int foo(int n, int k)
{
	static vector<vector<int>> dp(500, vector<int>(500, -1));

	if (n == 0)
		return 1;

	if (k == 1)
		return n < 2 ? 1 : 0;

	if (dp[n][k] == -1)
	{
		dp[n][k] = 0;

		for (int i = 0; i <= n; i++)
			dp[n][k] = (dp[n][k] + (2 * n + 1) * ((foo(n - i, k - 1) * (long long)foo(i, k - 1)) % inf)) % inf;
		for (int i = 0; i < n; i++)
			dp[n][k] = (dp[n][k] + foo (n - 1 - i, k - 1) * (long long)foo (i, k - 1)) % inf;
		for (int i = 0; i <= n + 1; i++)
			dp[n][k] = (dp[n][k] + (n * (n + 1)) * ((foo (n + 1 - i, k - 1) * (long long)foo (i, k - 1)) % inf)) % inf;
	}

	return dp[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false);

	int k;

	cin >> k;

	cout << foo(1, k) << endl;

	return 0;
}