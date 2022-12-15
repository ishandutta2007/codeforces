#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		solve();
}

ll solve(void)
{
	string s;
	cin >> s;

	int ret(1e9);

	// 01
	for (int i(0); i <= SZ(s); ++i)
	{
		int cnt1(0);
		for (int j(0); j < i; ++j)
			cnt1 += s[j] == '1';
		for (int j(i); j < SZ(s); ++j)
			cnt1 += s[j] == '0';
		ret = min(ret, cnt1);
	}
	for (int i(0); i <= SZ(s); ++i)
	{
		int cnt1(0);
		for (int j(0); j < i; ++j)
			cnt1 += s[j]=='0';
		for (int j(i); j < SZ(s); ++j)
			cnt1 += s[j] == '1';
		ret = min(ret, cnt1);
	}
	cout << ret << '\n';

	return 0;
}