#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	string str;

	cin >> str;

	vector<ll> cnt(26);
	vector<vector<ll>> dp(26, vector<ll>(26));

	for (auto it : str)
	{
		int q = it - 'a';

		for (int i = 0; i < 26; i++)
			dp[i][q] += cnt[i];
		cnt[q]++;
	}

	ll ans = *max_element(cnt.begin(), cnt.end());

	for (const auto &row : dp)
		ans = max(ans, *max_element(row.begin(), row.end()));

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