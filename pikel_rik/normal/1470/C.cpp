#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000;

int n, k;

int query(int q) {
	cout << "? " << q + 1 << endl;
	int ans;
	cin >> ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int pos;
	bool big = false;

	for (int iter = 0; iter < 1000; iter++) {
		int q = rng() % n;
		int val = query(q);

		if (val == k) {

		} else if (val < k) {
			pos = q;
			break;
		} else {
			pos = q;
			big = true;
			break;
		}
	}

	if (!big) {
		int lg = 32 - __builtin_clz(n) - 1;
		for (int i = lg - 1; i >= 0; i--) {
			int new_pos = (pos + (1 << i)) % n;
			if (query(new_pos) < k) {
				pos = new_pos;
			}
		}
		cout << "! " << (pos + 1) % n + 1 << endl;
	} else {
		int lg = 32 - __builtin_clz(n) - 1;
		for (int i = lg - 1; i >= 0; i--) {
			int new_pos = (pos + n - (1 << i)) % n;
			if (query(new_pos) > k) {
				pos = new_pos;
			}
		}
		cout << "! " << (pos + n - 1) % n + 1 << endl;
	}
	return 0;
}