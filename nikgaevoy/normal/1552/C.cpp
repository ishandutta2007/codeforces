#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector<pair<int, int>> edges(k);
	vector<int> taken;

	for (auto &[a, b] : edges)
	{
		cin >> a >> b;
		a--;
		b--;

		taken.push_back(a);
		taken.push_back(b);
	}

	sort(taken.begin(), taken.end());

	vector<int> rem;

	for (int j = 0; j < 2 * n; j++)
		if (!binary_search(taken.begin(), taken.end(), j))
			rem.push_back(j);

	for (int t = 0; t < rem.size() / 2; t++)
		edges.emplace_back(rem[t], rem[t + rem.size() / 2]);

	int ans = 0;

	assert(edges.size() == n);

	for (int i = 0; i < edges.size(); i++)
		for (int j = (i + 1); j < edges.size(); j++)
		{
			vector<pair<int, int>> vert{{edges[i].first,  i},
			                            {edges[i].second, i},
			                            {edges[j].first,  j},
			                            {edges[j].second, j}};

			sort(vert.begin(), vert.end());

			if (vert.front().second == vert[2].second)
				ans++;
		}

	cout << ans << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}