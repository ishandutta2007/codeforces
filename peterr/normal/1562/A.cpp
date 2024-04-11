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
		int a, b;
		cin >> a >> b;
		int ans = 0;
		int x = max(a, b / 2);
		for (int i = -5; i <= 5; i++)
		{
			int y = x + i;
			if (y < a || y > b)
				continue;
			ans = max(ans, b % y);
		}
		cout << ans << "\n";
	}
	return 0;
}