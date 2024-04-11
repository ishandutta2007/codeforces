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

		vector<int> b(n);
		for (auto &x : b) {
			cin >> x, x--;
		}

		vector<int> pref(2 * n, -1);
		for (int x : b) {
			pref[x] = 1;
		}

//		for (int i : pref) cout << i << ' '; cout << '\n';

		vector<int> ans(n + 1);
		ans[0] = ans[n] = 1;

		int lo = 0, hi = n;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;

			int i = 0, j = b[n - mid];
			for (; pref[i] == 1; i++);

			bool f = i < j;
			for (int k = 1; k < mid; k++) {
				for (++i; pref[i] == 1; i++);
				for (++j; pref[j] == -1; j++);
				f &= i < j;
			}

			if (!f)
				hi = mid - 1;
			else lo = mid;
		}

		for (int i = 1; i <= lo; i++) ans[i]++;

		lo = 0, hi = n;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;

			int i = 2 * n - 1, j = b[mid - 1];
			for (; pref[i] == 1; i--);

			bool f = j < i;
			for (int k = 1; k < mid; k++) {
				for (--i; pref[i] == 1; i--);
				for (--j; pref[j] == -1; j--);
				f &= j < i;
			}

			if (!f)
				hi = mid - 1;
			else lo = mid;
		}

		for (int i = 1; i <= lo; i++) ans[n - i]++;
		cout << count(ans.begin(), ans.end(), 2) << '\n';
	}
	return 0;
}