#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto &x : a) cin >> x, --x;

	vector<int> top(50, -1);
	for (int i = 0; i < n; i++) {
		if (top[a[i]] == -1) {
			top[a[i]] = i;
		}
	}

	while (q--) {
		int t;
		cin >> t;

		cout << top[--t] + 1 << ' ';
		for (int i = 0; i < 50; i++) {
			if (top[i] != -1 && top[i] < top[t]) {
				top[i] += 1;
			}
		}
		top[t] = 0;
	}
	cout << '\n';
	return 0;
}