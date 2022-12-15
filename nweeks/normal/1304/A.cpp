#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

void solve(void)
{
	ll x, y, a, b;
	cin >> x >> y >>  a >> b;

	ll k = (y-x)/(a+b);
	if (x + a * k == y - b * k)
		cout << k <<'\n';
	else
		cout << "-1\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}