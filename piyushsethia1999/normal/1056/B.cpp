#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	int q = n / m;
	int r = n % m;
	int tt = 0;
	for (int i = 1; i <= m ; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if ((i * i + j * j) % m == 0)
			{
				tt++;
			}
		}
	}
	int t1 = 0;
	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if ((i * i + j * j) % m == 0)
			{
				t1++;
			}
		}
	}
	int t2 = 0;
	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= r; ++j)
		{
			if ((i * i + j * j) % m == 0)
			{
				t2++;
			}
		}
	}
	int res = tt * (q * q) + t1 * q * 2ll + t2;
	cout << res;
}