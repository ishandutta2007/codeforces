#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x, --x;

		vector<int> ans;

		auto do_operation = [&](int i) -> void {
			if (i != 0) {
				ans.push_back(i);
				reverse(a.begin(), a.begin() + i + 1);
			}
		};

		bool possible = true;
		for (int x = n - 1; x > 0; x -= 2) {
			int i = find(a.begin(), a.end(), x) - a.begin();
			if (i % 2 != 0) {
				possible = false;
				break;
			}

			do_operation(i);

			int j = find(a.begin(), a.end(), x - 1) - a.begin();
			if (j % 2 == 0) {
				possible = false;
				break;
			}

			do_operation(j - 1);
			do_operation(j + 1);
			do_operation(2);
			do_operation(x);
		}

		if (!possible) {
			cout << "-1\n";
		} else {
			cout << (int) ans.size() << '\n';
			for (auto &x : ans) {
				cout << x + 1 << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}