#include <bits/stdc++.h>
using namespace std;

int n, ans[100000 + 5];

int query(int i) {
	if (i < 0 || n <= i)
		return INT_MAX;
	if (ans[i] == -1) {
		cout << "? " << i + 1 << endl;
		cin >> ans[i];
	}
	return ans[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(ans, -1, sizeof(ans));

	cin >> n;
	if (n == 1) {
		return cout << "! " << 1 << endl, 0;
	}

	if (query(0) < query(1)) {
		return cout << "! " << 1 << endl, 0;
	} else if (query(n - 2) > query(n - 1)) {
		return cout << "! " << n << endl, 0;
	}

	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (query(mid) < query(mid - 1) && query(mid) < query(mid + 1)) {
			return cout << "! " << mid + 1 << endl, 0;
		}
		if (query(mid) > query(mid - 1)) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	assert(false);
	return 0;
}