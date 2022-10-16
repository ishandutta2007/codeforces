#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, int>> s(n);
	vector<int> t(n);

	for (int i = 0; i < (int) s.size(); i++)
	{
		cin >> s[i].first;
		s[i].second = i;
	}

	for (auto &it : t)
		cin >> it;

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	vector<tuple<int, int, int>> moves;

	for (int l = 0, r = 0; l < n; l++)
	{
		if (s[l].first > t[l])
		{
			cout << "NO" << endl;

			return;
		}

		while (s[l].first < t[l])
		{
			while (r < n && s[r].first <= t[r])
				r++;

			if (r == n)
			{
				cout << "NO" << endl;

				return;
			}

			int d = min(t[l] - s[l].first, s[r].first - t[r]);

			moves.emplace_back(s[l].second, s[r].second, d);
			s[l].first += d;
			s[r].first -= d;
		}
	}

	cout << "YES" << endl;
	cout << moves.size() << endl;

	for (auto it : moves)
		cout << get<0>(it) + 1 << ' ' << get<1>(it) + 1 << ' ' << get<2>(it) << endl;
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