#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int mod = 1000000007;

int powm(int x, int y, int m) {
	int res = 1;
	x %= m;
	while (y) {
		if (y & 1ll) res = (res * x) % m;
		x = (x * x) % m;
		y >>= 1ll;
	}
	res = res % m;
	return res;
}

int fact[3000000] = {};

void facto() {
	fact[0] = 1;
	for (int i = 1; i < 2000005ll; ++i)
		fact[i] = (fact[i - 1] * i) % mod;
}

int c(int n, int r) {
	if (n < 0 || r < 0 || n - r < 0)
		return 0;
	return ((fact[n] * powm((fact[n - r] * fact[r]) % mod, mod - 2, mod)) % mod);
}

pair<int, int> v[30000];
int res[30000];

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	facto();
	int h; cin >> h;
	int w; cin >> w;
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;
	v[n] = {h, w};
	sort(v, v + n + 1);
	for (int i = 0; i < n + 1; ++i)
		res[i] = c(v[i].first - 1 + v[i].second - 1, v[i].first - 1);
	for (int i = 0; i < n + 1; ++i)
		for (int j = i + 1; j < n + 1; ++j) {
			res[j] = ((res[j] - (res[i] * c(v[j].first - v[i].first + v[j].second - v[i].second, v[j].second - v[i].second) % mod)) % mod + mod) % mod;
		}
	cout << res[n] << "\n";
}
// 658269278
// 662940250
// 975235983
// 324776544