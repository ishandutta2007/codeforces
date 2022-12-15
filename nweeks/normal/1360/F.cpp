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

int nb_diff(string a, string b)
{
	int n(0);
	for (int i(0); i < SZ(a); ++i)
		n += a[i] != b[i];
	return n;
}

ll solve(void)
{
	int n, m;
	cin >> n >> m;

	vector<string> words(n);
	for (auto &v : words)
		cin >> v;

	string cpy= "";
	for (auto c : words[0])
		cpy += c;
	for (int i(0); i < m; ++i)
		for (char c('a'); c <= 'z'; ++c)
		{
			cpy[i] = c;
			bool ok(true);
			for (auto s : words)
				ok = ok and nb_diff(cpy, s) <= 1;
			if (ok)
			{
				cout << cpy << '\n';
				return 0;
			}
			cpy[i] = words[0][i];
		}
		cout << -1 << '\n';
	return 0;
}