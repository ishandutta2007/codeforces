#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using bitset = array<uint64_t, 16>;

	constexpr int N = 1024;
	constexpr int W = 64;

	int n, s, d;
	cin >> n >> s >> d;

	vector<bitset> mask(s, bitset());
	for (int i = 0, c; i < s; i++) {
		cin >> c;
		for (int j = 0, x; j < c; j++) {
			cin >> x, --x;
			mask[i][x / W] |= 1ull << (x % W);
		}
	}

	vector<bitset> need(d, bitset());
	for (int i = 0, c; i < d; i++) {
		cin >> c;
		for (int j = 0, x; j < c; j++) {
			cin >> x, --x;
			need[i][x / W] |= 1ull << (x % W);
		}
	}

	auto do_xor = [&](bitset &x, const bitset &y) -> void {
		for (int i = 0; i < N / W; i++) {
			x[i] ^= y[i];
		}
	};

	bitset cur = bitset();
	vector<pair<bitset, int>> computed;
	auto recurse = [&](int i, int moves, const auto &self) -> void {
		if (i == s || i == 20) {
			computed.emplace_back(cur, moves);
		} else {
			self(i + 1, moves, self);
			do_xor(cur, mask[i]);
			self(i + 1, moves + 1, self);
			do_xor(cur, mask[i]);
		}
	};

	recurse(0, 0, recurse);

	sort(computed.begin(), computed.end());

	vector<int> ans(d, -1);
	auto recurse2 = [&](int i, int moves, const auto &self) -> void {
		if (i == s) {
			for (int j = 0; j < d; j++) {
				do_xor(cur, need[j]);
				auto it = lower_bound(computed.begin(), computed.end(), make_pair(cur, 0));
				if (it != computed.end() && it->first == cur) {
					if (ans[j] == -1) {
						ans[j] = moves + it->second;
					} else {
						ans[j] = min(ans[j], moves + it->second);
					}
				}
				do_xor(cur, need[j]);
			}
		} else {
			self(i + 1, moves, self);
			do_xor(cur, mask[i]);
			self(i + 1, moves + 1, self);
			do_xor(cur, mask[i]);
		}
	};

	recurse2(min(s, 20), 0, recurse2);
	for (int i = 0; i < d; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}