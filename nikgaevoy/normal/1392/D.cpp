#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

template<class T>
T &remin(T &x, const T &y)
{
	return x = min(x, y);
}


int foo(const string &str)
{
	vector<vector<int>> dp(str.size() + 1, vector<int>(4, str.size() + 1));

	dp[2][(str.front() == 'R' ? 2 : 0) + (str[1] == 'R' ? 1 : 0)] = 0;

	for (int i = 2; i < str.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			auto nxt = j * 2;

			for (int add = 0; add < 2; add++)
				if (nxt + add != 7 && nxt + add != 0)
					remin(dp[i + 1][(nxt + add) % 4], dp[i][j] + ((add == 0) != (str[i] == 'L') ? 1 : 0));
		}
	}

	int ans = numeric_limits<int>::max();

	for (int j = 0; j < 4; j++)
	{
		bool good = true;
		int val = j;

		for (int i = 0; i < 2; i++)
		{
			val %= 4;
			val *= 2;

			if (str[i] == 'R')
				val++;

			good &= val != 0 && val != 7;
		}

		if (good)
			remin(ans, dp.back()[j]);
	}

	return ans;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	string str;

	cin >> str;

	int ans = foo(str);

	str[0] ^= 'L' ^ 'R';

	remin(ans, foo(str) + 1);

	str[0] ^= 'L' ^ 'R';
	str[1] ^= 'L' ^ 'R';

	remin(ans, foo(str) + 1);

	str[0] ^= 'L' ^ 'R';

	remin(ans, foo(str) + 2);

	cout << ans << endl;
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

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}