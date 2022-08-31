#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 100 + 5;

int n, m, a[N][N];
int r[N], c[N];
int sum_r[N], sum_c[N];

void do_op_r(int i) {
	r[i] ^= 1;
	sum_r[i] = -sum_r[i];
	for (int j = 0; j < m; j++) {
		sum_c[j] -= 2 * a[i][j];
		a[i][j] = -a[i][j];
	}
}

void do_op_c(int j) {
	c[j] ^= 1;
	sum_c[j] = -sum_c[j];
	for (int i = 0; i < n; i++) {
		sum_r[i] -= 2 * a[i][j];
		a[i][j] = -a[i][j];
	}
}

bool f() {
	for (int i = 0; i < n; i++) {
		if (sum_r[i] < 0) {
			do_op_r(i);
			return true;
		}
	}
	for (int j = 0; j < m; j++) {
		if (sum_c[j] < 0) {
			do_op_c(j);
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			sum_r[i] += a[i][j];
			sum_c[j] += a[i][j];
		}
	}

	while (f());

	vector<int> ans_r, ans_c;
	for (int i = 0; i < n; i++) {
		if (r[i]) {
			ans_r.push_back(i + 1);
		}
	}
	for (int j = 0; j < m; j++) {
		if (c[j]) {
			ans_c.push_back(j + 1);
		}
	}

	cout << ans_r.size() << ' ';
	for (int i : ans_r) cout << i << ' '; cout << '\n';

	cout << ans_c.size() << ' ';
	for (int i : ans_c) cout << i << ' '; cout << '\n';
	return 0;
}