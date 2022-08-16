#include <bits/stdc++.h>
using namespace std;

int f(int x) {
	return (x * x + x) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> k(n);
	for (auto &x : k) cin >> x;

	vector<tuple<int, int, int>> v;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			v.emplace_back(abs(k[j] - k[i]), i, j);
		}
	}

	sort(v.rbegin(), v.rend());

	for (auto &[d, a, b] : v) {
		if (k[b] < k[a]) {
			swap(a, b);
		}
		cout << "? " << b + 1 << ' ' << a + 1 << endl;
		string yes;
		cin >> yes;
		if (yes == "Yes") {
			cout << "! " << b + 1 << ' ' << a + 1 << endl;
			return 0;
		}
	}
	cout << "! 0 0" << endl;
	return 0;
}