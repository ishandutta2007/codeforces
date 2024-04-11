#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<vector<int>> gr(n), rg(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
		rg[b].push_back(a);
	}

	vector<bool> alive(gr.size(), true), taken(gr.size());

	function<void(int)> slv = [&](int v)
	{
		if (v == gr.size())
			return;

		if (alive[v])
		{
			alive[v] = false;

			for (auto it : gr[v])
				if (alive[it])
					alive[it] = false;

			slv(v + 1);

			taken[v] = true;

			for (auto it : rg[v])
				if (taken[it])
					taken[v] = false;
		}
		else
			slv(v + 1);
	};

	slv(0);

	cout << count(taken.begin(), taken.end(), true) << endl;

	for (int i = 0; i < taken.size(); i++)
		if (taken[i])
			cout << i + 1 << ' ';
	cout << endl;
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