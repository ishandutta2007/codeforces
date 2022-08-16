#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<pair<int, int>> match(n, {-1, -1});
	vector<vector<int>> a(k);

	for (int i = 0, c; i < k; i++) {
		cin >> c, a[i].resize(c);
		for (auto &x : a[i]) {
			cin >> x, --x;
			if (match[x].first == -1) {
				match[x].first = i;
			} else {
				match[x].second = i;
			}
		}
	}

	vector<int> flip(k), p(k), on(k);
	vector<vector<int>> r(2, vector<int>(k));

	iota(p.begin(), p.end(), 0);
	fill(r[0].begin(), r[0].end(), 1);

	auto find = [&](int x) -> int {
		while (x != p[x]) {
			x = p[x];
		}
		return x;
	};

	auto find_state = [&](int x) -> int {
		int state = 0;
		while (x != p[x]) {
			state ^= flip[x];
			x = p[x];
		}
		state ^= flip[x];
		return state;
	};

	int ans = 0;
	auto merge = [&](int x, int y, bool f) -> void {
		int l1 = find(x), l2 = find(y);
		if (l1 == l2) {
			return;
		}
		if (r[0][l1] + r[1][l1] < r[0][l2] + r[1][l2]) {
			swap(l1, l2);
		}

		ans -= r[1][l1];
		ans -= r[1][l2];

		if ((find_state(x) == find_state(y)) == f) {
			if (on[l2]) {
				flip[l1] ^= 1;
				swap(r[0][l1], r[1][l1]);
			} else {
				flip[l2] ^= 1;
				swap(r[0][l2], r[1][l2]);
			}
		}

		on[l1] |= on[l2];
		p[l2] = l1, flip[l2] ^= flip[l1];
		r[0][l1] += r[0][l2];
		r[1][l1] += r[1][l2];
		if (!on[l1] && r[0][l1] < r[1][l1]) {
			flip[l1] ^= 1;
			swap(r[0][l1], r[1][l1]);
		}
		ans += r[1][l1];
	};

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (match[i].second != -1) {
				merge(match[i].first, match[i].second, true);
			} else {
				int l = find(match[i].first);
				if (find_state(match[i].first) == 0) {
					ans -= r[1][l];
					flip[l] ^= 1, swap(r[0][l], r[1][l]);
					ans += r[1][l];
				}
				on[l] = 1;
			}
		} else {
			if (match[i].second != -1) {
				merge(match[i].first, match[i].second, false);
			} else if (match[i].first != -1) {
				int l = find(match[i].first);
				if (find_state(match[i].first) == 1) {
					ans -= r[1][l];
					flip[l] ^= 1, swap(r[0][l], r[1][l]);
					ans += r[1][l];
				}
				on[l] = 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}