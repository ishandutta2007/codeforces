#include <bits/stdc++.h>
using namespace std;

void check(int n, vector<pair<int, int>> a, int m, int k) {
	vector<pair<int, int>> b = a;
	for (int i = 0; i < m; i++) {
		b[i].first += k;
		if (b[i].first > n) b[i].first -= n;

		b[i].second += k;
		if (b[i].second > n) b[i].second -= n;

		if (b[i].first > b[i].second) {
			swap(b[i].first, b[i].second);
		}
	}
	sort(b.begin(), b.end());

	if (b == a) {
		cout << "Yes"; exit(0);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<pair<int, int>> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;

		if (a[i].first > a[i].second) {
			swap(a[i].first, a[i].second);
		}
	}
	sort(a.begin(), a.end());

	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			check(n, a, m, i);
		}
	}
	cout << "No";

	return 0;
}