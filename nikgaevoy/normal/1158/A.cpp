#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<ll> b(n), g(m);

	for (auto &it : b)
		cin >> it;
	for (auto &it : g)
		cin >> it;

	sort(b.begin(), b.end());
	sort(g.begin(), g.end());

	if (g.front() < b.back())
	{
		cout << -1 << endl;

		return;
	}

	ll ans = accumulate(b.begin(), b.end() - 1, 0ll) * g.size() + accumulate(g.begin(), g.end(), 0ll);

	if (g.front() == b.back())
		cout << ans << endl;
	else
	{
		if (b.size() > 1 && g.size() > 1)
			cout << ans + b.back() - b[b.size() - 2] << endl;
		else
			cout << -1 << endl;
	}
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