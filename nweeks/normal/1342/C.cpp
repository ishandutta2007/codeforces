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
	int a, b, q;
	cin >> a >> b >> q;

	int mod = lcm(a,b);
	vector<ll> ok(mod+1);
	for (int i(0); i < mod; ++i)
		ok[i] = (i%a%b) != (i%b%a);
	for (int i(1); i <= mod; ++i)
		ok[i] += ok[i-1];
	while (q--)
	{
		ll lo, up;
		cin >> lo >> up;
		ll ans(0);

		if (lo%mod)
		{
			ll nxt = lo+mod - lo%mod;
			if (nxt > up)
			{
				cout << ok[up%mod] - ok[lo%mod-1] << ' ';
				continue ;
			}
			ans += ok[mod] - ok[lo%mod-1];
			lo = nxt;
		}
		ans += ok[up%mod];
		ans += ((up-lo)/mod) * ok[mod];

		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}