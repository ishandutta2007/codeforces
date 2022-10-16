#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

namespace std
{
	template<>
	struct hash<pair<ll, ll>>
	{
		auto operator()(const pair<ll, ll> &q) const noexcept
		{
			return std::hash<ll>{}(q.first ^ q.second);
		}
	};
}

mt19937 mt(736);

constexpr string_view yes = "YES", no = "NO";


class check
{
	ll x;
	unordered_set<pair<ll, ll>> used;

public:
	explicit check(ll x = 0) : x(x)
	{}

	bool operator()(ll a, ll b)
	{
		if (b < a)
			swap(a, b);

		if (a == x || b == x)
			return true;
		if (b < x || !used.emplace(a, b).second)
			return false;

		if (x > a && (b - x) % a == 0)
			return true;

		return (*this)(a, b % a);
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	ll a, b, x;

	cin >> a >> b >> x;

	if (x % gcd(a, b) != 0)
	{
		cout << no << endl;

		return;
	}

	cout << (check{x}(a, b) ? yes : no) << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

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