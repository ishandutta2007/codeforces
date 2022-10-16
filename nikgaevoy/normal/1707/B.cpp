#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


const ll mod = (1ull << 61) - 1;


ll mult(ll a, ll b)
{
	return a * (__int128) b % mod;
}


ll sqr(ll x)
{
	return mult(x, x);
}


ll powmod(ll x, ull y)
{
	return y ? y & 1u ? mult(x, powmod(x, y - 1)) : sqr(powmod(x, y / 2)) : 1;
}

ll inv(ll x)
{
	return powmod(x, mod - 2);
}


ll fact(int n)
{
	static vector<ll> dp = {1};

	while (n >= dp.size())
	{
		auto ans = mult(dp.back(), dp.size());
		dp.push_back(ans);
	}

	return dp[n];
}


ll ifact(int n)
{
	static vector<ll> dp = {1};

	while (n >= dp.size())
		dp.push_back(inv(fact(dp.size())));

	return dp[n];
}


ll C(int n, int k)
{
	return mult(mult(fact(n), ifact(k)), ifact(n - k));
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	if (arr.back() == 0)
	{
		cout << 0 << endl;
		return;
	}

	int zer = 0;

	while (arr.size() > 1)
	{
		vector<int> tmp;

		if (zer > 0)
		{
			tmp.push_back(arr.front());
			zer--;
		}

		for (int i = 1; i < arr.size(); i++)
			if (arr[i] != arr[i - 1])
				tmp.push_back(arr[i] - arr[i - 1]);
			else
				zer++;

		arr = move(tmp);
		sort(arr.begin(), arr.end());
	}

	cout << (arr.empty() ? 0 : arr.front()) << endl;
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