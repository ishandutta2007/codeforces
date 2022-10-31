#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(vector<int> a) {
	ll n = a.size();
	vector<ll> c(2);
	for (int i = 0; i < n; ++i) {
		a[i] %= 2;
		++c[a[i]];
	}
	auto eval = [&](const vector<ll>& a, const vector<ll>& b) -> ll {
		if (a.size() != b.size()) {
			return 1e18;
		}
		ll ret = 0;
		for (int i = 0; i < a.size(); ++i) {
			ret += abs(a[i] - b[i]);
		}
		return ret;
	};
	ll ret = 1e18;
	for (int b = 0; b < 2; ++b) {
		vector<ll> x[2];
		vector<ll> y[2];
		for (int i = 0; i < n; ++i) {
			x[(b + i) % 2].push_back(i);
			y[a[i]].push_back(i);
		}
		ret = min<ll>(ret, eval(x[0], y[0]) + eval(x[1], y[1]));
	}
	return (ret > 1e17) ? -1 : ret / 2;
}
int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 1; case_id <= n_cases; ++case_id) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cout << solve(a) << endl;
	}
	return 0;
}