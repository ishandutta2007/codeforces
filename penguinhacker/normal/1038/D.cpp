#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[500000];
vector<int> b, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] >= 0)
			b.push_back(a[i]);
		if (a[i] <= 0)
			c.push_back(-a[i]);
	}
	if (n == 1) {
		cout << a[0];
		return 0;
	}
	else if (n == 2) {
		cout << max(a[1] - a[0], a[0] - a[1]);
		return 0;
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	if (!b.empty() && !c.empty()) {
		cout << accumulate(b.begin(), b.end(), 0ll) + accumulate(c.begin(), c.end(), 0ll);
	}
	else if (!b.empty()) {
		cout << accumulate(b.begin(), b.end(), 0ll) - 2 * b[0];
	}
	else if (!c.empty()) {
		cout << accumulate(c.begin(), c.end(), 0ll) - 2 * c[0];
	}
	return 0;
}