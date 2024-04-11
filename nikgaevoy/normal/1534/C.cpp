#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr int mod = int(1e9) + 7;


template<class T>
auto sqr(T x)
{
	return x * x;
}


ll powmod(ll x, ull y)
{
	return y ? (y & 1 ? powmod(x, y - 1) * x : sqr(powmod(x, y / 2))) % mod : 1;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	array<vector<int>, 2> perms{};

	for (auto &row : perms)
	{
		row.resize(n);

		for (auto &it : row)
		{
			cin >> it;
			it--;
		}
	}

	array<vector<int>, 2> whs{};

	for (int i = 0; i < 2; i++)
	{
		whs[i].resize(perms[i].size());

		for (int j = 0; j < perms[i].size(); j++)
			whs[i][perms[i][j]] = j;
	}

	vector<bool> used(n);

	int cycles = 0;

	function<void(int)> dfs = [&](int v)
	{
		if (used[v])
			return;
		used[v] = true;

		dfs(whs[0][perms[1][v]]);
	};

	for (int i = 0; i < used.size(); i++)
		if (!used[i])
		{
			cycles++;

			dfs(i);
		}

	cout << powmod(2, cycles) << endl;
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