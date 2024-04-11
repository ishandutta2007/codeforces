#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> f1{ 0, 0, 0 };
	vector<int> f2{ 0, 0, 0 };

	vector<int> new_f1;
	vector<int> new_f2;
	ll ret = 0;
	for (int i = 0; i < n; ++i) {
		int prev_val = (i == 0 ? 1 : a[i - 1]);
		int cur_val = a[i];
		int max_k = min(cur_val, (int)sqrt(cur_val) + 23);
		new_f1.clear();
		new_f1.push_back(0);
		for (int k = 1; k <= max_k; ++k) {
			int prev_k = (prev_val + k - 1) / k;
			int prev_ret = (prev_k < f2.size() ? f2[prev_k] : f1[prev_val / prev_k]);
			int cur_ret = (prev_ret + (ll)(prev_k - 1) * i) % MOD;
			new_f1.push_back(cur_ret);
		}
		new_f2.clear();
		new_f2.push_back(0);
		for (int k = 1; k <= max_k; ++k) {
			int l = cur_val / k;
			int prev_k = (prev_val + l - 1) / l;
			int prev_ret = (prev_k < f2.size() ? f2[prev_k] : f1[prev_val / prev_k]);
			int cur_ret = (prev_ret + (ll)(prev_k - 1) * i) % MOD;
			new_f2.push_back(cur_ret);
		}
		f1.swap(new_f1);
		f2.swap(new_f2);
		ret = (ret + f2[1]) % MOD;
	}
	printf("%lld\n", ret);
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		solve();
	}
	return 0;
}