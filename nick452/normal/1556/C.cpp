#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(vector<ll> a) {
	ll ret = 0;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 1) {
			continue;
		}
		ll delta = 0;
		ll base = 0;
		for (int j = i + 1; j < n; ++j) {
			if (j % 2 == 1) {
				ll min_x = 1;
				ll max_x = a[i];
				min_x = max(min_x, -base);
				min_x = max(min_x, 1 - delta);
				max_x = min(max_x, a[j] - delta);
				if (min_x <= max_x) {
					ret += max_x - min_x + 1;
				}
			}
			if (j % 2 == 1) {
				delta -= a[j];
				base = min(base, delta);
			} else {
				delta += a[j];
			}
		}
	}
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cout << solve(a) << endl;
	}
	return 0;
}