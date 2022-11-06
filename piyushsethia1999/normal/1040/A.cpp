#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int cost[2];
	cin >> cost[0] >> cost[1];
	int m = min(cost[0], cost[1]);
	int tot = 0;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	for (int i = 0; i < (int)(n / 2); ++i)
	{
		if (a[i] != 2 && a[n - i - 1] != 2)
		{
			if (a[i] != a[n - i - 1]) {
				cout << -1;
				return 0;
			}
		}
		else if (a[i] == 2 && a[n - i - 1] == 2)
		{
			tot += m * 2;
		}
		else {
			if (a[i] == 2)
			{
				tot += cost[a[n - i - 1]];
			}
			else
				tot += cost[a[i]];
		}
	}
	if ((n & 1) && a[n / 2] == 2)
	{
		tot += m;
	}
	cout << tot;
}