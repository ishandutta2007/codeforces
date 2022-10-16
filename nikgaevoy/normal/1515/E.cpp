#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


int add(int a, int b, int mod)
{
	a += b;

	if (a >= mod)
		a -= mod;

	return a;
}


int mult(int a, int b, int mod)
{
	return int(a * (ll) b % mod);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, mod;

	cin >> n >> mod;

	vector<vector<int>> C(n + 1);

	for (int i = 0; i < C.size(); i++)
	{
		C[i].resize(i + 1);

		C[i][0] = 1;

		for (int j = 1; j < C[i].size(); j++)
			if (i - j < j)
				C[i][j] = C[i][i - j];
			else
				C[i][j] = add(C[i - 1][j - 1], C[i - 1][j], mod);
	}

	vector<int> pw2(n + 1);
	pw2[0] = 1;

	for (int j = 1; j < pw2.size(); j++)
		pw2[j] = add(pw2[j - 1], pw2[j - 1], mod);

	vector<vector<int>> dp(n + 1, vector<int>(n + 1));

	for (int j = 1; j < dp[0].size(); j++)
		dp[0][j] = pw2[j - 1];

	for (int k = 1; k < dp.size(); k++)
		for (int l = k; l <= n; l++)
			for (int prev = 2 * (k - 1) + 1; prev + 2 <= l; prev++)
			{
				auto we = l - prev - 1;

				assert(we > 0);
				assert(we <= l - k);

				dp[k][l] = add(dp[k][l], mult(dp[k - 1][prev], mult(dp[0][we], C[l - k][we], mod), mod), mod);
			}

	int ans = 0;

	for (int k = 0; k <= n; k++)
		ans = add(ans, dp[k][n], mod);

	cout << ans << endl;
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