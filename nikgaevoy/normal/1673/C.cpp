#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr int mod = int(1e9) + 7;


class solver
{
	vector<int> pal;
	vector<int> dp;

public:
	explicit solver(size_t n = 0) : dp(n)
	{
		for (auto i: ranges::iota_view(1, ssize(dp)))
		{
			auto s = to_string(i);
			string t(s.rbegin(), s.rend());

			if (s == t)
				pal.push_back(i);
		}

		dp[0] = 1;

		for (auto it: pal)
		{
			for (auto i: ranges::iota_view(0, ssize(dp) - it))
			{
				dp[i + it] += dp[i];
				dp[i + it] %= mod;
			}
		}
	}


	int operator()(int i)
	{
		return dp[i];
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	static solver slv(int(4e4) + 1);

	int n;

	cin >> n;

	cout << slv(n) << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

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