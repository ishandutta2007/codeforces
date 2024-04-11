#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 100;
long long a[MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		long long g = a[0];
		for (int i = 2; i < n; i += 2)
		{
			g = __gcd(g, a[i]);
		}
		long long ans = 0;
		bool good = true;
		for (int i = 1; i < n; i += 2)
		{
			if (a[i] % g == 0)
			{
				good = false;
				break;
			}
		}
		if (good)
		{
			ans = g;
			goto exit;
		}
		g = a[1];
		for (int i = 3; i < n; i += 2)
		{
			g = __gcd(g, a[i]);
		}
		good = true;
		for (int i = 0; i < n; i += 2)
		{
			if (a[i] % g == 0)
			{
				good = false;
				break;
			}
		}
		if (good)
		{
			ans = g;
			goto exit;
		}
		exit:;
		cout << ans << "\n";
	}
	return 0;
}