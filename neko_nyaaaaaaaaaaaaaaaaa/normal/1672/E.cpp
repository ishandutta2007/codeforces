#include <bits/stdc++.h>
using namespace std;

#define int long long

void answer(int area) {
	cout << "! " << area << endl;
	exit(0);
}

int ask(int w) {
	cout << "? " << w << endl;
	int h; cin >> h;
	return h;
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	// step 1: binary search for the total length of height 1
	int lo = 1, hi = 1000000000;
	while (lo < hi) {
		int mid = (lo + hi)/2;

		int h = ask(mid);
		if (h == 1) {
			// large
			hi = mid;
		} else {
			// small
			lo = mid+1;
		}
	}
	int ans = lo;

	int initial = lo;
	//int sumlen = initial - (n-1);
	// step 2: try every heights
	for (int h = 2; h <= n; h++) {
		// saves h-1 gaps
		// only one solution
		// total area at least "initial - (h-1)"
		// total area at most "initial - 1"
		int w = (initial-1)/h;
		int H = ask(w);

		if (H > 0) ans = min(ans, w*H);
	}

	answer(ans);

	return 0;
}