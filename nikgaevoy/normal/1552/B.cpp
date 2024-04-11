#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<array<int, 5>> arr(n);

	for (auto &row : arr)
		for (auto &it : row)
			cin >> it;

	auto cmp = [&arr](int a, int b)
	{
		int cnta = 0;

		for (int j = 0; j < 5; j++)
			if (arr[a][j] < arr[b][j])
				cnta++;

		return cnta >= 3;
	};

	int best = 0;

	for (int j = 0; j < arr.size(); j++)
		if (cmp(j, best))
			best = j;

//	cerr << best << endl;

	for (int j = 0; j < arr.size(); j++)
		if (j != best && !cmp(best, j))
		{
//			cerr << "bad: " << j << endl;
			cout << -1 << endl;

			return;
		}

	cout << best + 1 << endl;
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