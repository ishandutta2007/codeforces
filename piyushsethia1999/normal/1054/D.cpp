#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	// for (int i = 0; i < n; ++i)
	// {
	// 	a[i] = (1 << k) - 1 - a[i];
	// }
	std::map<int, int> m;
	m[0] = 1ll;
	int y = 0ll;
	int res = (n * (n + 1ll)) / 2ll;
	for (int i = 0; i < n; ++i)
	{
		y = y ^ a[i];
		if (m[y] > m[(1ll << k) - 1ll - y])
			y = (1ll << k) - y - 1ll;
		res -= m[y];
		m[y]++;
	}
	cout << res;
}