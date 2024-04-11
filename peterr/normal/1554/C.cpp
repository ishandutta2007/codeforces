#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		long long n, m;
		cin >> n >> m;
		long long ans = 0;
		while (n <= m)
		{
			long long x = n;
			for (int i = 0; i < 60; i++)
			{
				if (n & (1LL << i))
					continue;
				x += 1LL << i;
				if (x > m)
				{
					ans += 1LL << i;
					n += 1LL << i;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
}