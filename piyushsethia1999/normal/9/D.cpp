#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	std::vector<std::vector<ll> > a(36, std::vector<ll>(36, 0));
	a[0][0] = 1;
	for (ll n = 1; n < 36; ++n)
	{
		for (int h = 1; h <= n; ++h)
		{
			for (int keyofnode = 1; keyofnode <= n; ++keyofnode)
			{
				// May be left node height is h-1 and the right node less than h-1
				for (int th = 0; th < h-1 ; ++th)
					a[n][h] += ((a[keyofnode - 1][h-1])*(a[n - keyofnode][th]));

				// may be for right 
				for (int th = 0; th < h-1 ; ++th)
					a[n][h] += ((a[keyofnode - 1][th])*(a[n - keyofnode][h-1]));

				// may be both have h-1
				a[n][h] += (a[keyofnode-1][h-1]*a[n - keyofnode][h-1]);
			}	
		}
	}
	ll n, h;
	cin >> n >> h;
	ll res = 0;
	for (int i = h; i <= n; ++i)
	{
		res += a[n][i];
	}
	cout << res;
}