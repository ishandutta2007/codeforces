#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int k; cin >> k;
	int minx = 1000020000;
	for (int i = 1; i < k; ++i)
	{
		if (n % i == 0)
		{
			int x = n / i;
			x = x * k + i;
			minx = min(minx, x);
		}
	}
	cout << minx;
}