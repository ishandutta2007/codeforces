/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int left, right;
	long long m;
	cin >> left >> right >> m;
	bool found = false;
	for (int a = left; a <= right; a++) {
		long long prev = m / a * a;
		if (prev > 0 && prev + right - left >= m) {
			int b = right;
			int c = right - (int) (m - prev);
			cout << a << ' ' << b << ' ' << c << '\n';
			found = true;
			break;
		}
		long long next = prev + a;
		if (m + right - left >= next) {
			int c = right;
			int b = right - (int) (next - m);
			cout << a << ' ' << b << ' ' << c << '\n';
			found = true;
			break;
		}
	}
	assert(found);
	cout.flush();
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	
}