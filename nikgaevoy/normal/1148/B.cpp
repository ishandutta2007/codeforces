#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m, ta, tb, k;

	cin >> n >> m >> ta >> tb >> k;

	if (min(n, m) <= k)
	{
		cout << -1 << endl;

		return;
	}

	vector<int> a(n), b(m);

	for (auto &it : a)
		cin >> it;
	for (auto &it : b)
		cin >> it;

	int ans = 0;

	for (int i = 0; i <= k; i++)
	{
		int wh = lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
		wh += k - i;

		if (wh >= (int)b.size())
		{
			cout << -1 << endl;

			return;
		}

		ans = max(ans, b[wh]);
	}

	cout << ans + (ll) tb << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}