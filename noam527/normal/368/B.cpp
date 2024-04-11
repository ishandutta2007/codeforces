#include <iostream>
using namespace std;

int n, m, a[100005], dp[100005], l;
bool f[100005];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], f[i] = false;
	dp[n] = 1, f[a[n]] = true;
	for (int i = n - 1; i > 0; i--)
	{
		dp[i] = dp[i + 1];
		if (!f[a[i]]) dp[i]++, f[a[i]] = true;
	}
	for (int i = 0; i < m; i++) cin >> l, cout << dp[l] << endl;
}