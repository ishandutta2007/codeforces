#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);

template<class T>
auto &remax(T &x, const T &y)
{
	return x = max(x, y);
}


template<class T>
auto &remin(T &x, const T &y)
{
	return x = min(x, y);
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	string s, t;

	cin >> s >> t;

	vector<vector<pair<int, int>>> dp(t.size() + 1, vector<pair<int, int>>(t.size() + 1));

	for (int i = 0; i <= t.size(); i++)
		for (int j = 0; j <= t.size(); j++)
			dp[i][j] = {i, j};

	reverse(s.begin(), s.end());

	auto nxt = dp;

	for (auto it : s)
	{
		for (int l = 0; l <= t.size(); l++)
			for (int r = 0; r <= t.size(); r++)
			{
				auto &ans = nxt[l][r];

				ans = dp[l][r];

				if (l < t.size() && it == t[l])
					remax(ans, dp[l + 1][r]);
				if (r < t.size() && it == t[r])
					remax(ans, dp[l][r + 1]);
			}

		dp.swap(nxt);
	}

	bool ans = false;

	for (int i = 0; !ans && i <= t.size(); i++)
	{
		auto ret = dp[i][0];

		ans |= ret.first == t.size() && ret.second >= i;
	}

	cout << (ans ? "YES" : "NO") << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

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
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}