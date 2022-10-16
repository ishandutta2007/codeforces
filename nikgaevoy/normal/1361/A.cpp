#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<vector<int>> gr(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	vector<pair<int, int>> ord(n);

	for (int i = 0; i < n; i++)
	{
		int t;

		cin >> t;

		ord[i] = {t - 1, i};
	}

	sort(ord.begin(), ord.end());

	vector<int> ass(n, -1);

	for (auto it : ord)
	{
		set<int> used;

		for (auto ne : gr[it.second])
			used.insert(ass[ne]);

		used.erase(-1);

		while (!used.empty() && *used.rbegin() > it.first)
			used.erase(--used.end());

		if (used.count(it.first) || used.size() != it.first)
		{
			cout << -1 << endl;

			return;
		}

		ass[it.second] = it.first;
	}

	for (auto it :ord)
		cout << it.second + 1 << ' ';
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}