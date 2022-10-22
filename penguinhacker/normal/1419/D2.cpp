#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	vector<int> b(n);
	auto can = [&](int x) {
		for (int i = 0; i < x; ++i) {
			b[2 * i + 1] = a[i];
		}
		int pos = x;
		vector<int> rem;
		for (int i = 0; i <= 2 * x; i += 2) {
			while(pos < n && ((i > 0 && a[pos] <= b[i - 1]) || (i != 2 * x && a[pos] <= b[i + 1]))) {
				rem.push_back(a[pos++]);
			}
			if (pos == n) {
				return 0;
			}
			b[i] = a[pos++];
		}
		for (; pos < n; ++pos) {
			rem.push_back(a[pos]);
		}
		assert(rem.size() == n - (2 * x + 1));
		for (int i = 2 * x + 1; i < n; ++i) {
			b[i] = rem[i - (2 * x + 1)];
		}
		return 1;
	};
	int l = 0, r = (n - 1) / 2;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if (can(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	assert(can(l));
	cout << l << "\n";
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			cout << " ";
		}
		cout << b[i];
	}
	return 0;
}