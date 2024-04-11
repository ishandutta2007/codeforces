#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int x; cin >> x;
		int y; cin >> y;
		int d; cin >> d;
		if (x == y) {
			cout << 0 << "\n";
			continue;
		}
		int pp = 100000000000ll;
		if (y > x)
		{
			if (!((y - x) % d))
			{
				pp = min(pp, (y - x) / d);
			}
		}
		else {
			if (!((x - y) % d))
			{
				pp = min(pp, (x - y) / d);
			}
		}
		if ((y - 1) % d == 0)
		{
			pp = min(pp, (x - 1) / d + ((x - 1) % d ? 1 : 0) + (y - 1) / d);
		}
		if ((n - y) % d == 0)
		{
			pp = min(pp, (n - x) / d + ((n - x) % d ? 1 : 0) + (n - y) / d);
		}
		if (pp == 100000000000ll)
		{
			pp = -1;
		}
		cout << pp << "\n";
	}
}