#include <bits/stdc++.h>

using namespace std;

using ll = long long;


ll gcd (ll a, ll b)
{
	return b ? gcd (b, a % b) : a;
}


ll steps (ll n, ll l)
{
	l = abs (l);

	ll g = gcd (n, l);

	n /= g;
	l /= g;

	return n;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	ll n, k;

	cin >> n >> k;

	ll a, b;

	cin >> a >> b;

	ll mn = numeric_limits<ll>::max (), mx = 0;

	for (ll i = 0; i < n; i++)
	{
		ll t = i * k + b;

		mn = min (mn, steps (n * k, t - a));
		mx = max (mx, steps (n * k, t - a));

		t = i * k - b;

		mn = min (mn, steps (n * k, t - a));
		mx = max (mx, steps (n * k, t - a));
	}

	cout << mn << ' ' << mx << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}