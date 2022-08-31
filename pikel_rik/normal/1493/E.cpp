#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 * 1000;

int n;
bitset<N> l, r, mx, all[8];

bool operator>(const bitset<N> &x, const bitset<N> &y) {
	for (int i = N - 1; i >= 0; i--) {
		if (x[i] > y[i]) {
			return true;
		} else if (x[i] < y[i]) {
			return false;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	string _l, _r;
	cin >> _l >> _r;
	l = bitset<N>(_l), r = bitset<N>(_r);

	if (!r.any()) {
		return cout << 0 << '\n', 0;
	} else if (l == r) {
		for (int i = n - 1; i >= 0; i--) {
			cout << l[i];
		}
		return cout << '\n', 0;
	}

	for (int i = N - 1; i >= 0; i--) {
		if (r[i]) {
			if (!l[i]) {
				cout << string(n, '1') << '\n';
				return 0;
			}
			break;
		}
	}

	auto sub_one = [&](bitset<N> b) -> bitset<N> {
		for (int i = 0; i < N; i++) {
			if (b[i]) {
				for (int j = 0; j <= i; j++) {
					b[j].flip();
				}
				break;
			}
		}
		return b;
	};

	all[0] = mx = r;
	for (int i = 1; i < 8; i++) {
		all[i] = sub_one(all[i - 1]);
		if (all[i] == l) {
			break;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = i + 2; j < 8; j += 2) {
			all[i] ^= all[j - 1];
			all[i] ^= all[j];
			if (all[i] > mx) {
				mx = all[i];
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		cout << mx[i];
	}
	cout << '\n';
	return 0;
}