#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);

const int mod = 998244353;


template<class T>
auto sqr(const T &x)
{
	return x * x;
}


ll powmod(ll x, ll y)
{
	return y ? (y & 1 ? x * powmod(x, y - 1) : sqr(powmod(x, y / 2))) % mod : 1ll;
}


int fact(int n)
{
	static vector<int> dp = {1};

	while (n >= dp.size())
		dp.push_back(dp.back() * (ll) dp.size() % mod);

	return dp[n];
}


int ofact(int n)
{
	static vector<int> dp = {1};

	while (n >= dp.size())
		dp.push_back(powmod(fact(dp.size()), mod - 2));

	return dp[n];
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	ll d;

	cin >> d;

	vector<ll> dd, pd;

	for (ll i = 1; i * i <= d; i++)
		if (d % i == 0)
		{
			dd.push_back(i);

			if (i != d / i)
				dd.push_back(d / i);
		}

	sort(dd.begin(), dd.end());

	for (auto it : dd)
	{
		bool ok = it > 1;

		for (auto w : pd)
			ok &= it % w != 0;

		if (ok)
			pd.push_back(it);
	}

	cerr << dd.size() << '\t' << pd.size() << endl;

	vector<int> dcnt(dd.size());
	dcnt[0] = 1;

	for (int i = 1; i < dcnt.size(); i++)
		for (auto it : pd)
			if (dd[i] % it == 0)
			{
				int pw = 0;
				auto w = dd[i];

				while (w % it == 0)
				{
					w /= it;
					pw++;
				}

				auto prev = lower_bound(dd.begin(), dd.end(), w) - dd.begin();
				dcnt[i] = dcnt[prev] * (pw + 1);

				break;
			}

	int q;

	cin >> q;

	auto get_dcnt = [&dd, &dcnt](int w)
	{
		return dcnt[lower_bound(dd.begin(), dd.end(), w) - dd.begin()];
	};

	auto paths = [&](ll a, ll b)
	{
		vector<int> mult;

		for (auto it : pd)
		{
			int pwa = 0;
			int pwb = 0;

			while (a % it == 0)
			{
				pwa++;
				a /= it;
			}

			while (b % it == 0)
			{
				pwb++;
				b /= it;
			}

			if (pwa != pwb)
				mult.push_back(abs(pwa - pwb));
		}

		ll ans = fact(accumulate(mult.begin(), mult.end(), 0));

		for (auto it : mult)
		{
			ans *= ofact(it);
			ans %= mod;
		}

		return ans;
	};

	for (int i = 0; i < q; i++)
	{
		ll u, v;

		cin >> u >> v;

		auto g = __gcd(u, v);

		auto gp = paths(u, g) * (ll)paths(g, v) % mod;

		cout << gp << endl;
	}
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

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}