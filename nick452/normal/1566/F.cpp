#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<pair<ll, ll>> b;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		int at = lower_bound(a.begin(), a.end(), l) - a.begin();
		if (at < n && a[at] <= r) {
			continue;
		}
		b.push_back({l, r});
	}
	sort(b.begin(), b.end(), [](const pair<ll, ll>& x, const pair<ll, ll>& y) {
			return x.second < y.second || x.second == y.second && x.first > y.first;
		});
	vector<pair<ll, ll>> c;
	ll max_l = -1e15;
	for (const auto& w : b) {
		if (w.first > max_l) {
			max_l = w.first;
			c.push_back(w);
		}
	}
	b = std::move(c);
	m = b.size();
	if (m == 0) {
		return 0;
	}
	vector<ll> f(m + 1, 1e18);
	vector<ll> new_f(m + 1);
	vector<ll> s1(m + 1);
	vector<ll> s2(m + 1);
	f[0] = 0;
	int prev_k = 0;
	for (int i = 0; i < n; ++i) {
		ll cur = a[i];
		while (prev_k < m && i > 0 && b[prev_k].second <= a[i - 1]) {
			++prev_k;
		}
		int cur_k = prev_k;
		while (cur_k < m && b[cur_k].second <= a[i]) {
			++cur_k;
		}
		int last_k = cur_k;
		while (last_k < m && (i + 1 >= n || b[last_k].first <= a[i + 1])) {
			++last_k;
		}
		int shift_k = prev_k;

		for (int k = prev_k; k < cur_k; ++k) {
			s1[k] = f[k] - b[k].second;
			if (k > prev_k) s1[k] = min(s1[k], s1[k - 1]);
		}
		for (int k = cur_k - 1; k >= prev_k; --k) {
			s2[k] = f[k] - b[k].second * 2;
			if (k + 1 < cur_k) s2[k] = min(s2[k], s2[k + 1]); 
		}
		for (int k = last_k; k >= cur_k; --k) {
			ll p2 = (k == cur_k ? 0 : b[k - 1].first - a[i]);
			new_f[k] = f[cur_k] + p2;
			while (shift_k < cur_k && a[i] - b[shift_k].second > p2) {
				++shift_k;
			}
			if (prev_k < shift_k) {
				new_f[k] = min(new_f[k], s1[shift_k - 1] + p2 * 2 + a[i]);
				/*
				for (int d = prev_k; d < shift_k; ++d) {
					ll p1 = a[i] - b[d].second;
					new_f[k] = min(new_f[k], f[d] + p1 + p2 * 2);
				}
				*/
			}
			if (shift_k < cur_k) {
				new_f[k] = min(new_f[k], s2[shift_k] + p2 + a[i] * 2);
				/*
				for (int d = shift_k; d < cur_k; ++d) {
					ll p1 = a[i] - b[d].second;
					new_f[k] = min(new_f[k], f[d] + p1 * 2 + p2);
				}
				*/
			}
			/*
			ll expect_f = 1e18;
			for (int d = prev_k; d <= cur_k; ++d) {
				ll p1 = (d == cur_k ? 0 : a[i] - b[d].second);
				expect_f = min(expect_f, f[d] + p1 + p2 + min(p1, p2));
			}
			if (expect_f != new_f[k]) {
				printf("ERROR\n");
				exit(0);
			}
			*/
		}
		for (int k = cur_k; k <= last_k; ++k) {
			f[k] = new_f[k];
		}
	}
	return f[m];
}

int main()
{
#ifdef _MSC_VER
	freopen("f.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; ++case_id) {
		cout << solve() << endl;
	}
	return 0;
}