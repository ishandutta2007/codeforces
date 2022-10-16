#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);

int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<vector<int>> last(n, vector<int>(m, 4));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (i == 0)
				last[i][j]--;
			if (i == n - 1)
				last[i][j]--;
			if (j == 0)
				last[i][j]--;
			if (j == m - 1)
				last[i][j]--;
		}

	bool ans = true;

	for (auto &row : last)
		for (auto &it : row)
		{
			int tmp;

			cin >> tmp;

			if (tmp > it)
				ans = false;
		}

	if (ans)
	{
		cout << "YES" << endl;

		for (auto &row : last)
		{
			for (auto &it : row)
				cout << it << ' ';
			cout << '\n';
		}
	}
	else
		cout << "NO" << endl;
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