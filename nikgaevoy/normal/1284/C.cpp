#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


int fact(int n, int mod)
{
	static vector<int> dp = {1};

	if (n >= dp.size())
		dp.push_back((n * (ll) fact(n - 1, mod)) % mod);

	return dp[n];
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, mod;

	cin >> n >> mod;

	ll ans = 0;

	for (int l = 1; l <= n; l++)
	{
		ans += (fact(l, mod) * (ll)fact(n + 1 - l, mod) % mod) * (n + 1 - l);
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