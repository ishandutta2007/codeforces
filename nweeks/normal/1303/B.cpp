#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 2e5;

void solve(void)
{
	ll n, g, b;
	cin >> n >> g >> b;
	

	ll l(1), r(1e18);

	while (l < r)
	{
		ll m = (l+r)/2;

		ll good_seasons = m/(g+b);
		ll good = good_seasons * g;
		ll bad = good_seasons * b;
		ll le = m - (g+b) * good_seasons;
		good += min(g, le);
		le -= g;
		bad += max(0LL, le);
		if (good < (n+1)/2 or good + bad < n)
			l = m+1;
		else
			r = m;
	}
	cout << l << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}