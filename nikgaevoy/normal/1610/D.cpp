#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr int mod = 1e9 + 7;


constexpr int mult(int a, int b)
{
	return a * (ll) b % mod;
}


constexpr int sqr(int x)
{
	return mult(x, x);
}

constexpr int powmod(int x, unsigned y)
{
	return y ? (y & 1u ? mult(x, powmod(x, y - 1)) : sqr(powmod(x, y / 2))) : 1;
}

constexpr int inv(int x)
{
	return powmod(x, mod - 2);
}

int fact(size_t n)
{
	static vector<int> dp = {1};

	while (n >= dp.size())
	{
		auto tmp = mult(dp.size(), dp.back());
		dp.push_back(tmp);
	}

	return dp[n];
}


int C(int n, int k)
{
	return mult(fact(n), mult(inv(fact(k)), inv(fact(n - k))));
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	sort(arr.begin(), arr.end(), [](int a, int b)
	{
		return __builtin_ctz(a) < __builtin_ctz(b);
	});

	ll ans = 0;

	for (int l = 0, r; l < ssize(arr); l = r)
	{
		for (r = l; r < ssize(arr) && __builtin_ctz(arr[l]) == __builtin_ctz(arr[r]); r++);

		int cur = r - l;
		int rem = ssize(arr) - r;

		if (arr[l] % 2 != 0)
			ans += mult(powmod(2, cur) - 1, powmod(2, rem));
		else
			ans += mult(powmod(2, cur - 1) - 1, powmod(2, rem));
	}

	cout << ans % mod << endl;
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