#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}

	vector<vector<long long>> a(n, vector<long long>(n));

	int zero_i = -1, zero_j = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (!a[i][j]) {
				zero_i = i;
				zero_j = j;
			}
		}
	}

	bool f = zero_i == 0;
	long long sum = accumulate(a[f].begin(), a[f].end(), 0ll);
	long long sum_i = accumulate(a[zero_i].begin(), a[zero_i].end(), 0ll);

	a[zero_i][zero_j] = sum - sum_i;

	bool ok = true;
	for (int rot = 0; rot < 2; rot++) {
		for (int i = 0; i < n; i++) {
			ok &= accumulate(a[i].begin(), a[i].end(), 0ll) == sum;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i < j) {
					swap(a[i][j], a[j][i]);
				}
			}
		}
	}

	long long diag = 0, anti_diag = 0;
	for (int i = 0; i < n; i++) {
		diag += a[i][i];
		anti_diag += a[i][n - i - 1];
	}

	ok &= diag == sum;
	ok &= anti_diag == sum;

	if (ok && 1 <= a[zero_i][zero_j]) {
		cout << a[zero_i][zero_j] << '\n';
	} else {
		cout << "-1\n";
	}
	return 0;
}