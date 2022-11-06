#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int mod = 1e9 + 7;

int sum(int l, int r) {
	l--;
	l = l % mod;
	r = r % mod;
	r = (((r * (r + 1ll)) / 2ll) % mod + mod) % mod;
	l = (((l * (l + 1ll)) / 2ll) % mod + mod) % mod;
	return ((r - l) % mod + mod) % mod;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	int res = 0;
	for (int i = 1, la; i <= min(m, n); i = la + 1)
	{
		la = min(n / (n / i), m);
		res = (res + ((n / i) % mod) * sum(i, la)) % mod;
	}
	res = (((((n % mod) * (m % mod)) % mod - res) % mod) + mod) % mod;
	cout << res << "\n";
}