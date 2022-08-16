#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> a(n);
	for (auto &x : a) cin >> x;

	long long ans = 0;
	vector<long long> pref_mn(n), pref_mx(n);

	auto pop = [](long long x) -> int {
		return __builtin_popcountll(x);
	};

	auto is_contained = [](long long l1, long long r1, long long l2, long long r2) -> bool {
		return l2 <= l1 && r1 <= r2;
	};

	auto is_strictly_contained = [&](long long l1, long long r1, long long l2, long long r2) -> bool {
		return is_contained(l1, r1, l2, r2) && (l1 != l2 || r1 != r2);
	};

	auto recurse = [&](int l, int r, auto &&self) -> void {
		if (l != r) {
			int m = l + (r - l) / 2;
			self(l, m, self);
			self(m + 1, r, self);

			partial_sum(a.begin() + m + 1, a.begin() + r + 1, pref_mn.begin() + m + 1, [](auto x, auto y) { return x < y ? x : y; });
			partial_sum(a.begin() + m + 1, a.begin() + r + 1, pref_mx.begin() + m + 1, [](auto x, auto y) { return x > y ? x : y; });

			int correct_pref = 0;
			for (int i = m + 1; i <= r; i++) {
				correct_pref += pop(pref_mn[i]) == pop(pref_mx[i]);
			}

			long long suf_mn = LLONG_MAX, suf_mx = LLONG_MIN;

			static vector<int> cnt_mn(61), cnt_mx(61);
			fill(cnt_mn.begin(), cnt_mn.end(), 0);
			fill(cnt_mx.begin(), cnt_mx.end(), 0);

			int j1 = m + 1, j2 = m + 1;
			for (int i = m; i >= l; i--) {
				suf_mn = min(suf_mn, a[i]);
				suf_mx = max(suf_mx, a[i]);
				while (j1 <= r && is_contained(pref_mn[j1], pref_mx[j1], suf_mn, suf_mx)) {
					cnt_mn[pop(pref_mn[j1])] -= 1;
					cnt_mx[pop(pref_mx[j1])] -= 1;
					j1 += 1;
				}
				while (j2 <= r && !is_strictly_contained(suf_mn, suf_mx, pref_mn[j2], pref_mx[j2])) {
					correct_pref -= pop(pref_mn[j2]) == pop(pref_mx[j2]);
					cnt_mn[pop(pref_mn[j2])] += 1;
					cnt_mx[pop(pref_mx[j2])] += 1;
					j2 += 1;
				}
				if (pop(suf_mn) == pop(suf_mx)) {
					ans += j1 - m - 1;
				}
				ans += correct_pref;
				if (j1 < j2) {
					if (pref_mx[j1] > suf_mx) {
						ans += cnt_mx[pop(suf_mn)];
					} else if (pref_mn[j1] < suf_mn) {
						ans += cnt_mn[pop(suf_mx)];
					}
				}
			}
		} else {
			ans += 1;
		}
	};

	recurse(0, n - 1, recurse);
	cout << ans << '\n';
	return 0;
}