#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<vector<ll>> d(n, vector<ll>(n));
	ll shift = (1LL << 62);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ll dx = x[i] - x[j];
			ll dy = y[i] - y[j];
			ll t = dx * dx + dy * dy;
			shift = min(shift, t & (-t));
			d[i][j] = d[j][i] = t;
		}
	}
	vector<int> results;
	for (int i = 0; i < n; ++i) {
		if (d[0][i] / shift % 2 == 0) {
			results.push_back(i);
		}
	}
	printf("%d\n", results.size());
	for (int idx : results) {
		printf("%d ", idx + 1);
	}
	printf("\n");
	return 0;
}