#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

const int mod = 998244353;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<bool> alive(n);
	vector<pair<int, int>> portals(n);

	for (int i = 0; i < portals.size(); i++)
	{
		int x, y, s;

		cin >> x >> y >> s;

		portals[i] = {x, y};
		alive[i] = (s == 1);
	}

	assert(is_sorted(portals.begin(), portals.end()));

	vector<int> dp(portals.size()), ps(portals.size() + 1);

	auto norm = [](int &x)
	{
		if (x >= mod)
			x -= mod;
		if (x < 0)
			x += mod;
	};

	for (int i = 0; i < dp.size(); i++)
	{
		int x = portals[i].first;
		int y = portals[i].second;

		auto dir = lower_bound(portals.begin(), portals.end(), pair{y, 0}) - portals.begin();

		dp[i] = ps[i] - ps[dir] + x - y;
		norm(dp[i]);
		ps[i + 1] = ps[i] + dp[i];
		norm(ps[i + 1]);
	}

	ll ans = portals.back().first + 1;

	for (int i = 0; i < portals.size(); i++)
		if (alive[i])
			ans += dp[i];

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