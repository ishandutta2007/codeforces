#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	long long sum = 0;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		sum += x;
		if (a.empty()) {
			a.push_back(x);
		} else {
			if (x % 2 == a.back() % 2) {
				a.pop_back(); continue;
			} else {
				a.push_back(x);
			}
		}
	}
	for (int i: a) {
		if (i % 2) sum--;
	}
	cout << sum/2;

	return 0;
}