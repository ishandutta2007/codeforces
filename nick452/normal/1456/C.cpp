#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve_one_case(int n) {
	int m;
	cin >> m;
	m = min(m, n);
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		a[i] = c;
	}
	ll results = std::numeric_limits<ll>::min();
	sort(a.begin(), a.end());
	if (m == 0) {
		results = 0;
		for (int i = 0; i < n; ++i) {
			results += a[i] * i;
		}
		return results;
	}
	vector<ll> sa(n + 1);
	vector<ll> sb(n + 1);
	vector<ll> sc(n + 1);
	for (int i = 0; i < n; ++i) {
		sa[i + 1] = sa[i] + a[i];
		sb[i + 1] = sb[i] + a[i] * i;
		sc[i + 1] = sc[i] + a[i] * (i / (m + 1));
	}

	for (int max_bucket = 0; max_bucket <= n; ++max_bucket) {
		if ((ll)max_bucket * (ll)(m + 1) < (ll)n) {
			continue;
		}
		int d = (n - max_bucket) / m;
		ll sum = sc[d * (m + 1)];
		if (d < max_bucket)
		{
			int rem = (n - max_bucket) % m + 1;
			sum += (sa[d * (m + 1) + rem] - sa[d * (m + 1)]) * d;
			int length = max_bucket - (d + 1);
			sum += (sb[n] - sb[n - length]) - (sa[n] - sa[n - length]) * (n - max_bucket);
		}
		results = max(results, sum);
	}
	return results;
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin >> n) cout << solve_one_case(n) << endl;
	return 0;
}