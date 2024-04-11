#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

constexpr int mod = 998244353;

int prod(int a, int b)
{
	return int(a * (ll) b % mod);
}

int sqr(int x)
{
	return prod(x, x);
}

int powmod(int x, unsigned y)
{
	return y ? y & 1u ? prod(x, powmod(x, y - 1)) : sqr(powmod(x, y / 2)) : 1;
}

int recip(int x)
{
	return powmod(x, mod - 2);
}

int fact(int n)
{
	static vector<int> dp = {1};

	while (n >= dp.size())
		dp.push_back(prod(dp.size(), dp.back()));

	return dp[n];
}


int rfact(int n)
{
	static vector<int> dp = {1};

	while (n >= dp.size())
		dp.push_back(recip(fact(dp.size())));

	return dp[n];
}


int C(int n, int k)
{
	return prod(fact(n), prod(rfact(k), rfact(n - k)));
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> arr(n);

	for (auto &it: arr)
		cin >> it;

	vector<ll> ps(arr.size() + 1);

	for (auto i: ranges::iota_view(1, ssize(ps)))
		ps[i] = ps[i - 1] + arr[i - 1];

	assert(is_sorted(ps.begin(), ps.end()));

	int ans = 1;

	vector<pair<ll, int>> blocks;

	for (int l = 0, r; l < ssize(ps); l = r)
	{
		for (r = l; r < ssize(ps) && ps[l] == ps[r]; r++);

		blocks.emplace_back(ps[l], r - l);
	}

	for (auto [val, a]: blocks)
		if (2 * val < ps.back())
		{
			auto q = ranges::lower_bound(blocks, pair{ps.back() - val, 0});

			assert(q != blocks.end());

			auto b = val + q->first == ps.back() ? q->second : 0;

			if (val == 0)
			{
				a--;
				b--;
			}

			ll sum = 0;

			for (int k = 0; k <= min(a, b); k++)
				sum += prod(C(a, k), C(b, k));

			ans = prod(ans, int(sum % mod));
		}
		else if (2 * val == ps.back())
		{
			if (val == 0)
				a -= 2;

			ans = prod(ans, powmod(2, a));
		}

	cout << ans << '\n';
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

#ifdef STRESS
	for (int cnt = 1;; cnt++)
	{
		stringstream ss, in1, out1, in2, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "fail: " << cnt << endl;
			cout << ss.str();
			cout << "solve:" << endl;
			cout << out1.str();
			cout << "stress:" << endl;
			cout << out2.str();

			break;
		}
		else if (cnt % 100 == 0)
			cout << "ok: " << cnt << endl;
	}
#endif

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}