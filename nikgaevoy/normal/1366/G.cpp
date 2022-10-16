#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

const int inf = 1e9 + 7;

template<class T>
T &remin(T &x, const T &y)
{
	return x = min(x, y);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	string s, t;

	cin >> s >> t;

	vector<int> jmp(s.size(), -1);
	vector<int> pos;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			if (!pos.empty())
			{
				jmp[pos.back()] = i + 1;
				pos.pop_back();
			}
		}
		else
			pos.push_back(i);
	}

	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, inf));

	dp[0][0] = 0;

	for (int i = 0; i < dp.size(); i++)
		for (int j = 0; j < dp[i].size(); j++)
		{
			if (i != s.size() && j != t.size() && s[i] == t[j])
				remin(dp[i + 1][j + 1], dp[i][j]);
			if (i != s.size())
				remin(dp[i + 1][j], dp[i][j] + 1);
			if (i != s.size() && jmp[i] != -1)
				remin(dp[jmp[i]][j], dp[i][j]);
		}

	assert(dp.back().back() < inf);

	cout << dp.back().back() << endl;
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