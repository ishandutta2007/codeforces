#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#ifdef LOCAL
mt19937 mt(736);
#else
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
#endif

const int antihack = uniform_int_distribution<int>{}(mt);

namespace std
{
	template<>
	struct hash<pair<int, int>>
	{
		std::size_t operator()(pair<int, int> const &s) const noexcept
		{
			return std::hash<ll>{}(s.first * ll(1ull << 32u) + (s.second ^ antihack));
		}
	};
}

constexpr int mod = 998244353;


int get_nxt(int val, int bnd)
{
	auto cnt = (val + bnd - 1) / bnd;
	auto nxt = val / cnt;

	return nxt;
}


auto get_params()
{
	vector<vector<int>> params = {{}};

	for (int i = 1; i <= (int) 1e5; i++)
	{
		params.emplace_back();
		auto &q = params.back();

		for (int j = 1; j * j <= i + j; j++)
		{
			q.push_back(j);
			q.push_back((i + j - 1) / j);
		}

		sort(q.begin(), q.end());
		q.erase(unique(q.begin(), q.end()), q.end());
	}

	return params;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	const static auto params = get_params();

	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	static vector<int> dp = {0}, ndp;
	dp = {0};

	ll ans = 0;

	for (int i = 0; i < n; i++)
	{
		auto val = arr[i];

		ndp.clear();
		ndp.reserve(params[val].size());

		int prev = 0;

		for (auto bnd: params[arr[i]])
		{
			auto cnt = (val + bnd - 1) / bnd;
			auto nxt = val / cnt;

			while (prev + 1 < dp.size() && params[arr[i - 1]][prev + 1] <= nxt)
				prev++;

			ndp.push_back((dp[prev] + (cnt - 1) * (i + 1ll)) % mod);
		}

		ans += ndp.back();
		dp.swap(ndp);
	}

	cout << ans % mod << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	cout << 1 << endl;

	constexpr int n = 1e5;

	cout << n << endl;

	uniform_int_distribution<int> uid(5e4, 1e5);

	for (int i = 0; i < n; i++)
		cout << uid(mt) << ' ';
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

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	stringstream ss;

	gen(ss);

	solve(ss);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}