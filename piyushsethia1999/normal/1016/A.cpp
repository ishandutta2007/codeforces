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
	#else
	#define print(...) 0
	#endif
	ll n; cin >> n;
	ll m; cin >> m;
	vector<ll> a(n); for (int o = 0; o < n; ++o) { cin >> a[o]; }	
	ll rem = 0;
	for (int i = 0; i < n; ++i)
	{
		rem += a[i];
		cout << rem / m << " ";
		rem %= m;
	}
}