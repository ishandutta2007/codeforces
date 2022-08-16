#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, p;
	cin >> n >> m >> p;

	vector<long long> a(n);
	for (auto &x : a) {
		string s;
		cin >> s;
		x = bitset<64>(s).to_ullong();
	}

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int best = 0;
	long long best_mask = 0;

	for (int iter = 0; iter < 60; iter++) {
		int idx = rng() % n;

		vector<int> set_bits;
		for (int j = 0; j < m; j++) {
			if (a[idx] >> j & 1) {
				set_bits.push_back(j);
			}
		}

		auto convert_to = [&](long long mask) -> int {
			int new_mask = 0;
			for (int j = 0; j < set_bits.size(); j++) {
				if (mask >> set_bits[j] & 1) {
					new_mask |= 1 << j;
				}
			}
			return new_mask;
		};

		auto convert_from = [&](int mask) -> long long {
			long long new_mask = 0;
			for (int j = 0; j < set_bits.size(); j++) {
				if (mask >> j & 1) {
					new_mask |= 1ll << set_bits[j];
				}
			}
			return new_mask;
		};

		const int pop = set_bits.size();
		const int all = convert_to(a[idx]);

		vector<int> cnt(1 << pop);
		for (int i = 0; i < n; i++) {
			cnt[convert_to(a[i] & a[idx]) ^ all] += 1;
		}

		for (int i = 0; i < pop; i++) {
			for (int mask = 0; mask < (1 << pop); mask++) {
				if (mask >> i & 1) {
					cnt[mask] += cnt[mask ^ (1 << i)];
				}
			}
		}

		for (int mask = 0; mask < (1 << pop); mask++) {
			if (cnt[mask] >= (n + 1) / 2 && __builtin_popcount(mask ^ all) > best) {
				best = __builtin_popcount(mask ^ all);
				best_mask = convert_from(mask ^ all);
			}
		}
	}

	for (int j = m - 1; j >= 0; j--) {
		cout << (best_mask >> j & 1);
	}
	cout << '\n';
	return 0;
}