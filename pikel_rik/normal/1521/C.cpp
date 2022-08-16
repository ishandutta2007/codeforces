#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	auto query = [&](int t, int i, int j, int x) -> int {
		cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
		int ans;
		cin >> ans;
		return ans;
	};

	while (T--) {
		int n;
		cin >> n;

		int one = -1;
		for (int i = 1; i < n; i += 2) {
			int q = query(2, i - 1, i, 1);
			if (q == 1) {
				one = i - 1;
				break;
			} else if (q == 2 && query(2, i, i - 1, 1) == 1) {
				one = i;
				break;
			}
		}

		if (one == -1) {
			one = n - 1;
		}

		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			if (i != one) {
				ans[i] = query(1, one, i, n - 1);
			} else ans[i] = 1;
		}
		cout << "! ";
		for (auto &x : ans) cout << x << ' ';
		cout << endl;
	}
	return 0;
}