#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	std::vector<int> cnt(n);
	std::vector<int> mm(n);
	int maxofall = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> cnt[i];
		int y = 0;
		for (int j = 0; j < cnt[i]; ++j)
		{
			int u;
			cin >> u;
			y = max(u, y);
		}
		mm[i] = y;
		maxofall = max(y, maxofall);
	}
	int totl = 0;
	for (int i = 0; i < n; ++i)
	{
		totl += ((maxofall - mm[i]) * cnt[i]);
	}
	cout << totl;
}