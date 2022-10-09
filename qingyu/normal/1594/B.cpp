/*
2021.10.09
*/
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		long long n, k;
		cin >> n >> k;
		long long r = 1, ans = 0;
		for (int i = 0; i < 32; ++i)
		{
			if (k >> i & 1)
			{
				ans = (ans + r) % mod;
			}
			r = (r * n) % mod;
		}
		cout << ans << '\n';
	}
}