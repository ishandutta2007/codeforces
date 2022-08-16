#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> b(n / 2);
	for (auto &x : b) cin >> x;

	vector<long long> a(n);
	a[0] = 0, a[n - 1] = b[0];

	for (int i = 1; i < n / 2; i++) {
		long long prev = a[i - 1];
		long long next = a[n - i];
		a[i] = prev, a[n - i - 1] = b[i] - prev;
		if (a[n - i - 1] > next) {
			long long diff = a[n - i - 1] - next;
			a[i] += diff, a[n - i - 1] -= diff;
		}
	}

	for (auto &x : a) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}