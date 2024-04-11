#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<vector<int>> gr(n);
	vector<int> type(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
	}

	for (int i = 0; i < gr.size(); i++)
		if (type[i] < 2)
			for (auto it : gr[i])
				type[it] = max(type[it], type[i] + 1);

	assert(7 * count(type.begin(), type.end(), 2) <= 4 * n);

	cout << count(type.begin(), type.end(), 2) << '\n';

	for (int i = 0; i < type.size(); i++)
		if (type[i] == 2)
			cout << i + 1 << ' ';
	cout << '\n';
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
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}