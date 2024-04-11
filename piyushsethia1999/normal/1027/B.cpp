#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	int n; cin >> n;
	int q; cin >> q;
	if (n & 1)
	{
		while (q--)
		{
			int x; cin >> x;
			int y; cin >> y;
			if ((x + y) & 1)
			{
				cout << (n * n + x * n + y + 2ll - n) / 2ll << "\n";
			}
			else
			{
				cout << (x * n + y - n + 1ll) / 2ll << "\n";
			}
		}
	}
	else
	{
		while (q--)
		{
			int x; cin >> x;
			int y; cin >> y;
			if (!((x + y) & 1)) {
				if (!(x & 1))
					y--;
				cout << (n * x + y - n + 1ll) / 2ll << "\n";
			}
			else
			{
				if (!(x & 1))
					y++;
				cout << (n * n - n + n * x + y ) / 2ll << "\n";
			}
		}
	}
}