#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

constexpr int mod = 998244353;

ll sqr(ll x)
{
	return x * x;
}

int powmod(int x, int y)
{
	return y == 0 ? 1 : int((y % 2 == 0 ? sqr(powmod(x, y / 2)) : powmod(x, y - 1) * (ll) x) % mod);
}

int fact(int n)
{
	static vector<int> dp = {1};

	while (n >= dp.size())
		dp.push_back(int(dp.back() * (ll) dp.size() % mod));

	return dp[n];
}

int rfact(int n)
{
	static vector<int> dp = {1};

	while (n >= dp.size())
		dp.push_back(powmod(fact(int(dp.size())), mod - 2));

	return dp[n];
}

int C(int n, int k)
{
	return int(fact(n) * (ll)rfact(n - k) % mod * rfact(k) % mod);
}


int mm(int n)
{
	static vector<int> dp = {1, 1};

	if (n >= dp.size())
	{
		mm(n - 1);

		dp.push_back(int((mm(n - 1) + mm(n - 2) * (n - 1ll)) % mod));
	}

	return dp[n];
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	ll sum = 0;

	for (int prs = 0; 2 * prs <= n; prs += 2)
	{
		ll add = C(n - prs, prs);
		add *= C(prs, prs / 2);
		add %= mod;
		add *= fact(prs / 2);
		add %= mod;

		auto rem = n - 2 * prs;

		add *= mm(rem);
		add %= mod;

		sum += add;
	}

	sum %= mod;

	cout << sum << '\n';
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
			cout << ss.str() << endl;
			cout << "solve:" << endl;
			cout << out1.str() << endl;
			cout << "stress:" << endl;
			cout << out2.str() << endl;

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