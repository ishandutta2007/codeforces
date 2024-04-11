#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
	if (n%7 == 0) return n;
	for (int d = 0; d <= 9; d++) {
		int m = n - n%10 + d;
		if (m%7 == 0) return m;
	}
	assert(0);
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		cout << solve(n) << '\n';
	}
}