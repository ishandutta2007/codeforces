#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> deg(n);
	for (int i = 1; i < n; i++) {
		int p; cin >> p;
		deg[p-1]++;
	}
	sort(begin(deg), end(deg), greater<int>());
	while (deg.back() == 0) deg.pop_back();
	deg.push_back(1);

	int k = size(deg);
	for (int i = 0; i < k; i++) {
		deg[i] = max(0, deg[i]-k+i);
	}

	int lo = -1, hi = n;
	while (hi-lo > 1) {
		int extra = (lo+hi)/2;
		int total = 0;
		for (int rem: deg) total += max(0, rem-extra);
		(total <= extra ? hi : lo) = extra;
	}

	return k + hi;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		cout << solve() << '\n';
	}
}