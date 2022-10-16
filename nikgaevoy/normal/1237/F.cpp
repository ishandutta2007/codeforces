#include <bits/stdc++.h>


using namespace std;


using ll = long long;

const int mod = 998244353;


mt19937 mt(736);

template<class T>
T sqr(T x)
{
	return x * x;
}


ll powmod(ll x, ll y)
{
	return y ? (y & 1 ? x * powmod(x, y - 1) : sqr(powmod(x, y / 2))) % mod : 1;
}


ll fact(int x)
{
	static vector<ll> dp = {1};

	if (x >= dp.size())
		dp.push_back((fact(x - 1) * x) % mod);

	return dp[x];
}


ll ofact(int x)
{
	static vector<ll> dp = {1};

	if (x >= dp.size())
	{
		ofact(x - 1);
		dp.push_back(powmod(fact(x), mod - 2));
	}

	return dp[x];
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int h, w, n;

	cin >> h >> w >> n;

	vector<bool> vert(h), hor(w);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
		{
			int r, c;

			cin >> r >> c;
			r--;
			c--;

			vert[r] = true;
			hor[c] = true;
		}

	int zv = count(vert.begin(), vert.end(), false);
	int zh = count(hor.begin(), hor.end(), false);

	auto mn = (zv + zh) / 3;
	mn = min(mn, min(zv, zh));
	mn++;

	vector<vector<int>> dphor(w + 1, vector<int>(mn)),
			dpvert(h + 1, vector<int>(mn));

	dphor[0][0] = 1;
	dpvert[0][0] = 1;

	for (int i = 1; i < dphor.size(); i++)
	{
		dphor[i] = dphor[i - 1];

		for (int j = 1; j < mn; j++)
			if (i > 1 && !hor[i - 1] && !hor[i - 2])
			{
				dphor[i][j] += dphor[i - 2][j - 1];

				if (dphor[i][j] >= mod)
					dphor[i][j] -= mod;
			}
	}

	for (int i = 1; i < dpvert.size(); i++)
	{
		dpvert[i] = dpvert[i - 1];

		for (int j = 1; j < mn; j++)
			if (i > 1 && !vert[i - 1] && !vert[i - 2])
			{
				dpvert[i][j] += dpvert[i - 2][j - 1];

				if (dpvert[i][j] >= mod)
					dpvert[i][j] -= mod;
			}
	}

	ll ans = 0;

	auto A = [](int n, int k) -> ll {
		if (k < 0 || k > n)
			return 0;

		return (fact(n) * powmod(fact(n - k), mod - 2)) % mod;
	};

	auto C = [](int n, int k) -> ll {
		if (k < 0 || k > n)
			return 0;

		return fact(n) * ofact(n - k) % mod * ofact(k) % mod;
	};

	cerr << mn << endl;

	for (int i = 0; i < mn; i++)
		for (int j = 0; i + j < mn; j++)
		{
			ll fs = dphor.back()[i] * C(zh - 2 * i, j);
			ll sn = dpvert.back()[j] * C(zv - 2 * j, i);
			fs %= mod;
			sn %= mod;

			fs *= fact(i);
			sn *= fact(j);
			fs %= mod;
			sn %= mod;

			ans += fs * sn;
			ans %= mod;
		}

	cout << ans << endl;
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

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}