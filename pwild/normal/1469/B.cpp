#include <bits/stdc++.h>
using namespace std;

void solve() {
	int res = 0;
	for (int z = 0; z < 2; z++) {
		int n; cin >> n;
		int best = 0, sum = 0;
		while (n--) {
			int a; cin >> a;
			sum += a;
			best = max(best,sum);
		}
		res += best;
	}
	cout << res << endl;
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}