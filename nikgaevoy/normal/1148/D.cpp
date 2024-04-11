#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, int>> arr(n);

	for (auto &it : arr)
		cin >> it.first >> it.second;

	vector<pair<pair<int, int>, int>> p, m;

	for (int i = 0; i < (int) arr.size(); i++)
	{
		auto it = arr[i];

		if (it.second < it.first)
			p.emplace_back(it, i);
		else
		{
			it.first *= -1;
			it.second *= -1;
			m.emplace_back(it, i);
		}
	}

	if (p.size () < m.size ())
		p.swap (m);

	sort (p.begin (), p.end (), [](const auto &a, const auto &b) {
		return a.first.second < b.first.second;
	});

	cout << p.size () << endl;

	for (auto it : p)
		cout << it.second + 1 << ' ';
	cout << endl;
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