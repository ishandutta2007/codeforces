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
	bool ex[2] = {false, false};
	for (auto c : s)
		ex[c-'0'] = true;
	if (!ex[0] or !ex[1])
		cout << s << '\n';
	else
	{
		for (int i(0); i < SZ(s); ++i)
		{
			if (s[i]=='1')
				cout << 0;
			cout << s[i];
			if (s[i]=='0')
				cout << '1';
		}
		cout << '\n';
	}

	return 0;
}