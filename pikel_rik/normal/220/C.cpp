#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n), inv_a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i], inv_a[--a[i]] = i;
	}

	vector<int> b(n), inv_b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i], inv_b[--b[i]] = i;
	}

	set<int> equal;
	set<pair<int, int>> left, right;
	int add_left = 0, add_right = 0;

	int init_ans = n;
	for (int i = 0; i < n; i++) {
		init_ans = min(init_ans, abs(inv_a[i] - inv_b[i]));
		if (inv_a[i] < inv_b[i]) {
			init_ans = min(init_ans, inv_b[i] - inv_a[i]);
			right.emplace(inv_b[i] - inv_a[i], i);
		} else if (inv_a[i] > inv_b[i]) {
			init_ans = min(init_ans, inv_a[i] - inv_b[i]);
			left.emplace(inv_a[i] - inv_b[i], i);
		} else {
			equal.insert(i);
		}
	}

	cout << init_ans << '\n';

	for (int i = 1; i < n; i++) {
		add_left += 1, add_right -= 1;
		for (auto it = equal.begin(); it != equal.end(); it = equal.erase(it)) {
			if (inv_a[*it] != 0) {
				left.emplace(1 - add_left, *it);
			} else {
				right.emplace(n - 1 - add_right, *it);
			}
		}

		for (auto it = right.begin(); it != right.end(); it = right.erase(it)) {
			if (add_right + it->first == 0) {
				equal.insert(it->second);
			} else {
				break;
			}
		}

		if (inv_a[b[i - 1]] != 0) {
			left.erase(make_pair(inv_a[b[i - 1]] - add_left + 1, b[i - 1]));
			if (inv_a[b[i - 1]] != n - 1) {
				right.emplace(n - 1 - inv_a[b[i - 1]] - add_right, b[i - 1]);
			} else {
				equal.insert(b[i - 1]);
			}
		}

		int ans = n;
		if (!equal.empty()) {
			ans = 0;
		}
		if (!left.empty()) {
			ans = min(ans, add_left + left.begin()->first);
		}
		if (!right.empty()) {
			ans = min(ans, add_right + right.begin()->first);
		}
		cout << ans << '\n';
	}
	return 0;
}