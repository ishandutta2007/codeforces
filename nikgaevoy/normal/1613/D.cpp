#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<int mod = 998244353>
class mod_t
{
	int x;

public:
	static constexpr int value = mod;

	explicit mod_t(int x = 0) : x(x)
	{}

	mod_t &operator+=(const mod_t &rhs)
	{
		x += rhs.x;

		if (x >= mod)
			x -= mod;

		return *this;
	}

	explicit operator int() const
	{
		return x;
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	copy_n(istream_iterator<decltype(arr)::value_type>(cin), arr.size(), arr.begin());

	auto dp = vector(2, vector<mod_t<>>(n + 2));

	dp[0][0] = mod_t(1);

	for (auto it: arr)
	{
		dp[0][it + 1] += dp[0][it + 1];
		dp[1][it + 1] += dp[1][it + 1];
		dp[0][it + 1] += dp[0][it];

		if (it > 0)
		{
			dp[1][it - 1] += dp[1][it - 1];
			dp[1][it - 1] += dp[0][it - 1];
		}
	}

	mod_t ans{};

	for (const auto &row: dp)
		for (const auto &it: row)
			ans += it;

	ans += decltype(ans)(decltype(ans)::value - 1);

	cout << int(ans) << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (weakly_incrementable auto it: ranges::iota_view(0, t))
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