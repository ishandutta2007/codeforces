#include <bits/stdc++.h>
using namespace std;

template <typename T, int N>
struct sub_maximum {
	array<T, N> a;
	sub_maximum(T e = std::numeric_limits<T>::min()) {
		a.fill(e);
	}

	bool add(const T &x) {
		for (int i = 0; i < N; i++) {
			if (x > a[i]) {
				copy(a.rbegin() + 1, a.rbegin() + N - i, a.rbegin());
				return a[i] = x, true;
			}
		}
		return false;
	}

	const T operator[](int i) const {
		return a[i];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	if (n <= 4 || m <= 4) {
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += accumulate(a[i].begin(), a[i].end(), 0ll);
		}
		cout << sum << '\n';
		return 0;
	}

	if (n > m) {
		vector<vector<int>> new_a(m, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				new_a[j][i] = a[i][j];
			}
		}
		new_a.swap(a);
		swap(n, m);
	}

	long long ans = 0;

	vector<long long> row_sums(n), column_sums(m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			row_sums[i] += a[i][j];
			column_sums[j] += a[i][j];
		}
	}

	{
		sub_maximum<long long, 4> four;
		for (int i = 0; i < n; i++) {
			four.add(row_sums[i]);
		}
		ans = max(ans, four[0] + four[1] + four[2] + four[3]);
	}

	{
		sub_maximum<long long, 4> four;
		for (int j = 0; j < m; j++) {
			four.add(column_sums[j]);
		}
		ans = max(ans, four[0] + four[1] + four[2] + four[3]);
	}

	for (int i = 0; i < n; i++) {
		sub_maximum<long long, 3> three;
		for (int j = 0; j < m; j++) {
			three.add(column_sums[j] - a[i][j]);
		}
		ans = max(ans, row_sums[i] + three[0] + three[1] + three[2]);
	}

	for (int j = 0; j < m; j++) {
		sub_maximum<long long, 3> three;
		for (int i = 0; i < n; i++) {
			three.add(row_sums[i] - a[i][j]);
		}
		ans = max(ans, column_sums[j] + three[0] + three[1] + three[2]);
	}

	for (int i1 = 0; i1 < n; i1++) {
		for (int i2 = i1 + 1; i2 < n; i2++) {
			sub_maximum<long long, 2> two;
			for (int j = 0; j < m; j++) {
				two.add(column_sums[j] - a[i1][j] - a[i2][j]);
			}
			ans = max(ans, row_sums[i1] + row_sums[i2] + two[0] + two[1]);
		}
	}
	cout << ans << '\n';
	return 0;
}