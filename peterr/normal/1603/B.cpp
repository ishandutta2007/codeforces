#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		if (x == y)
			cout << x << "\n";
		else if (x > y)
			cout << x + y << "\n";
		else
		{
			int xx = x * (y / x);
			int ans = xx + (y - xx) / 2;
			cout << ans << "\n";
			assert(ans % x == y % ans);
		}
	}
	return 0;
}