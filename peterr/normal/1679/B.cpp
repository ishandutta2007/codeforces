#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
pair<int, int> a[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		ans += a[i].first;
	}
	int when = -1;
	int val = 0;
	for (int i = 1; i <= q; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int j, x;
			cin >> j >> x;
			if (a[j].second > when)
				ans -= a[j].first;
			else
				ans -= val;
			a[j] = {x, i};
			ans += x;
		}
		else
		{
			cin >> val;
			when = i;
			ans = (long long) val * n;
		}
		cout << ans << "\n";
	}
	return 0;
}