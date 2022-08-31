#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int total = 0;
	for (int i = 0; i < n; i++) {
		total += a[i][i];
	}

	int q;
	cin >> q;

	string s;
	while (q--) {
		int t;
		cin >> t;

		if (t <= 2) {
			int i;
			cin >> i; --i;
			total -= a[i][i];
			a[i][i] = 1 - a[i][i];
			total += a[i][i];
		} else {
			s += (total & 1 ? '1' : '0');
		}
	}
	cout << s << '\n';
	return 0;
}