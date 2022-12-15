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
		cout << solve() << '\n';
}

ll solve(void)
{
	ll len, bal;
	cin >> len >> bal;
	string s;
	cin >> s;
	ll tot_bal(0);
	for (auto c : s)
		tot_bal -= 2*(c-'0')-1;

	int sol(0);
	vector<ll> prefixes(len+1);
	prefixes[0] = 0;
	for (int i = 0; i < len; ++i)
		prefixes[i+1] = prefixes[i] - (2*(s[i]-'0')-1);

	for (int i = 0; i < len+1; ++i)
		if (!tot_bal and prefixes[i]==bal)
			return -1;
	if (!tot_bal) return 0;
	for (int i = 0; i < len; ++i)
		if ((bal-prefixes[i])%tot_bal == 0 and (bal-prefixes[i]) * tot_bal >= 0)
			++sol;
	return sol;
}