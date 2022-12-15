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
	ll h, c , t;
	cin >> h >> c >> t;

	if (h + c >= 2 * t)
	{
		cout << 2 << '\n';
		return 0;
	}
	int n = ceil((double)(h-c)/(2. * t - h-c));
	if (n%2==0) ++n;

	double even = abs( (h+c)/2. - t);
	double odd_bef = abs(t - (h+c)/2. - (h-c)/(2.*n));
	int ans = 2;
	if (odd_bef < even)
		ans = n;
	if (odd_bef == even)
		ans = min(ans, n);
	n -= 2;
	if (n > 0)
	{
		double odd_aft = abs((t - (h+c)/2. - (h-c)/(2. * n)));
		if (odd_aft < min(odd_bef, even))
			ans = n;
		if (odd_aft == min(odd_bef, even))
			ans= min(ans, n);
	}
	cout << ans << '\n';

	return 0;
}