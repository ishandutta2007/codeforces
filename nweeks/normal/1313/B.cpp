#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

void solve(void)
{
	ll n, x,y;
	cin >> n>> x >> y;
	ll l, r;

	// Find max :
	l = 1, r = n;
	while (l < r)
	{
		ll mid = (l+r+1)/2;

		ll reach(0);
		if (mid < x)
			reach = mid;
		else
			reach = mid+1;
		if (x + y - mid >= 1)
			l = mid;
		else
			r = mid-1;
	}
	ll mx = l;
	l = 0, r = n-1;
	while (l < r)
	{
		ll mid = (l+r+1)/2;
		ll reach(0);
		if (n - mid +1 > x)
			reach = n - mid + 1;
		else
			reach = n - mid;
		ll s = max(1LL, x + y - n+1);
		ll e = n;
		ll inside = e-s + 1 - (y >= s and y <= e);
		//cout << mid << ' ' << s << ' ' << e << ' ' << inside << ' ' << reach << endl;
		if (x + y - reach + 1  <= n and  inside >= mid)
			l = mid;
		else
			r = mid-1;
	}
	ll mn = n - l;

	cout << mn << ' ' << mx << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--)
		solve();
}