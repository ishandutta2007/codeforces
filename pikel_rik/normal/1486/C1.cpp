#include <bits/stdc++.h>
using namespace std;

int query(int l, int r) {
	if (l == r)
		return -1;
	cout << "? " << l + 1 << ' ' << r + 1 << endl;
	int ans;
	cin >> ans;
	return ans - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int second_mn = query(0, n - 1);

	if (query(second_mn, n - 1) == second_mn) {
		int lo = second_mn + 1, hi = n - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (query(second_mn, mid) == second_mn) {
				hi = mid;
			} else lo = mid + 1;
		}
		cout << "! " << lo + 1 << endl;
	} else {
		int lo = 0, hi = second_mn - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (query(mid, second_mn) == second_mn) {
				lo = mid;
			} else hi = mid - 1;
		}
		cout << "! " << lo + 1 << endl;
	}
	return 0;
}