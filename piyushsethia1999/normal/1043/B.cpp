#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n;
	cin >> n;
	vector<int> a(n + 1); for (int o = 0; o < n; o++) { cin >> a[o + 1]; }
	a[0] = 0;
	std::vector<int> res;
	for (int l = 1; l <= n; ++l)
	{
		bool ok = true;
		std::vector<int> x(l);
		for (int i = 0; i < l; ++i)
		{
			x[i] = a[i + 1] - a[i];
		}
		for (int i = l; i < n; ++i)
		{
			if (a[i + 1] - a[i] != x[i % l])
			{
				ok = false;
			}
		}
		if (ok)
		{
			res.pb(l);
		}
	}
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << " ";
	}
}