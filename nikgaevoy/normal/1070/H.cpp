#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;

	vector<string> info(n);
	for (auto &s : info)
		cin >> s;

	vector<pair<string, int>> lst;

	for (int id = 0; id < n; id++)
	{
		const auto &s = info[id];
		vector<string> who;
		for (int len = 1; len <= (int)s.size(); len++)
		{
			for (int i = 0; i + len <= (int)s.size(); i++)
				who.push_back(s.substr(i, len));
		}

		sort(who.begin(), who.end());
		who.resize(unique(who.begin(), who.end()) - who.begin());

		for (const auto &t : who)
			lst.emplace_back(t, id);
	}

	sort(lst.begin(), lst.end());
	int q;
	cin >> q;

	for (int it = 0; it < q; it++)
	{
		string qr;
		cin >> qr;

		int pos_l = int(lower_bound(lst.begin(), lst.end(), pair<string, int>{qr, 0}) - lst.begin());
		int pos_r = int(lower_bound(lst.begin(), lst.end(), pair<string, int>{qr, n}) - lst.begin());

		if (pos_l != pos_r)
			cout << pos_r - pos_l << ' ' << info[lst[pos_l].second] << "\n";
		else
			cout << "0 -\n";
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