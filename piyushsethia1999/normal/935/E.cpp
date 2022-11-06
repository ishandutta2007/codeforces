#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

string s;
std::vector<int> pos;
int MIN;

std::vector<std::vector<int> > dptable(int i, int j)
{
	if (i == j)
		return (std::vector<std::vector<int> > (2, std::vector<int> (1, s[i] - '0')));
	int curr = i + 1;
	std::vector<std::vector<int> > dptable1 = dptable(curr, pos[curr]);
	curr = pos[curr] + 2;
	std::vector<std::vector<int> > dptable2 = dptable(curr, pos[curr]);

	std::vector<std::vector<int> > dptabler(2, std::vector<int> (min((int)(dptable1[0].size() + dptable2[0].size() + 1), MIN + 1)));
	int siz = dptabler[0].size();
	int siz1 = dptable1[0].size();
	int siz2 = dptable2[0].size();
	for (int i = 0; i < siz; ++i)
	{
		dptabler[0][i] = -1000000000;
		dptabler[1][i] = 1000000000;
	}
	//if plus

	for (int i = 1; i < siz; ++i)
	{
		for (int j = max(0ll, i - siz2); j <= min(i - 1, siz1 - 1); ++j) {
			dptabler[0][i] = max(dptabler[0][i], dptable1[0][j] + dptable2[0][i - 1 - j]);
		}
		for (int j = max(0ll, i - siz2); j <= min(i - 1, siz1 - 1); ++j) {
			dptabler[1][i] = min(dptabler[1][i], dptable1[1][j] + dptable2[1][i - 1 - j]);
		}
	}

	//if minus

	for (int i = 0; i < siz; ++i)
	{

		// 0 <= i - j <= siz2-1

		// j <= i
		// j >= i - siz2 + 1


		for (int j = max(0ll, i - siz2 + 1); j <= min(i, siz1 - 1); ++j) {
			dptabler[0][i] = max(dptabler[0][i], dptable1[0][j] - dptable2[1][i - j]);
		}
		for (int j = max(0ll, i - siz2 + 1); j <= min(i, siz1 - 1); ++j) {
			dptabler[1][i] = min(dptabler[1][i], dptable1[1][j] - dptable2[0][i - j]);
		}
	}

	return dptabler;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	cin >> s;
	int p; cin >> p;
	int m; cin >> m;
	MIN = p;
	stack<int> S;
	pos.resize(s.size());
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == ')')
		{
			int y = S.top();
			S.pop();
			pos[y] = i;
			pos[i] = y;
		}
		else if (s[i] == '(')
		{
			S.push(i);
		}
		else if (s[i] == '?') { }
		else
		{
			pos[i] = i;
		}
	}
	std::vector<std::vector<int> > res = dptable(0, s.size() - 1);
	cout << res[0][p];
}