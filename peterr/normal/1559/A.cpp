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
		int n;
		cin >> n;
		int ans = (1 << 30) - 1;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			ans = ans & x;
		}
		cout << ans << "\n";
	}
	return 0;
}