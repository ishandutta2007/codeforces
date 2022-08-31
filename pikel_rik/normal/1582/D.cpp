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
		for (auto &x : a) cin >> x;

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] < a[j];
		});

		int not_done = n;
		vector<int> b(n), other;

		for (int i = 0; i < n; i++) {
			if (i + 1 < n && a[ind[i]] == a[ind[i + 1]] && not_done - 2 >= 2) {
				b[ind[i]] = 1;
				b[ind[i + 1]] = -1;
				i += 1;
				not_done -= 2;
			} else {
				other.push_back(ind[i]);
			}
		}

		if (other.size() % 2 == 0) {
			for (int i = 1; i < (int) other.size(); i += 2) {
				b[other[i]] = a[other[i - 1]];
				b[other[i - 1]] = -a[other[i]];
			}
		} else {
			for (int i = 1; i + 2 < (int) other.size(); i += 2) {
				b[other[i]] = a[other[i - 1]];
				b[other[i - 1]] = -a[other[i]];
			}
			int i = other[other.size() - 1];
			int j = other[other.size() - 2];
			int k = other[other.size() - 3];
			b[i] = a[j] * a[k];
			b[j] = a[i] * a[k];
			b[k] = -2 * a[i] * a[j];
		}

		for (int i = 0; i < n; i++) {
			cout << b[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}