#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;		
	#endif
	ll n; cin >> n;
	ll q; cin >> q;
	vector<ll> v(n); for (ll o = 0; o < n; ++o) { cin >> v[o]; }
	vector<ll> c(n); for (ll o = 0; o < n; ++o) { cin >> c[o]; c[o]--;}
	for (ll i = 0; i < q; ++i)
	{
		ll a; cin >> a;
		ll b; cin >> b;
		std::vector<ll> dp(n);
		std::vector<ll> maxc(n, -100000000000000000);
		ll max1 = -100000000000000000, max2 = -100000000000000000;
		ll c1 = -1, c2 = -1;
		for (ll i = 0; i < n; ++i)
		{
			if(c1 != c[i]) 
				dp[i] = max1 + v[i] * b;
			else
				dp[i] = max2 + v[i] * b;
			dp[i] = max(dp[i], maxc[c[i]] + v[i] * a);
			dp[i] = max(dp[i], v[i] * b);
			if(dp[i] > max1)
			{
				if(c1 == c[i])
					max1 = dp[i];
				else
				{
					max2 = max1;
					c2 = c1;
					max1 = dp[i];
					c1 = c[i];
				}
			}
			else if(max2 < dp[i] && c[i] != c1)
			{
				max2 = dp[i];
				c2 = c[i];
			}
			maxc[c[i]] = max(maxc[c[i]], dp[i]);
		}
		cout << max(max1, 0ll) << "\n";
	}
}