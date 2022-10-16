#include <bits/stdc++.h>
using namespace std;

#define prev jgpqwepjogew

void check(int l, int r, int prev, int ri) {
	if (l > r) return;
	int len = (r - l + 1);

	int rt;
	if (len % 2) {
		rt = (r + l)/2;
	} else {
		// must be same parity with r
		rt = (r + l)/2;
		if ((rt % 2) != (r % 2)) rt++;
	}

	if (ri) {
		if ((rt % 2) != (prev % 2)) {
			cout << 0; exit(0);
		}
	} else {
		if ((rt % 2) == (prev % 2)) {
			cout << 0; exit(0);
		}
	}

	check(l, rt-1, rt, 0);
	check(rt+1, r, rt, 1);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	check(1, n, n, 1);
	cout << 1;

	return 0;
}