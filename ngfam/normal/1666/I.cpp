#include <bits/stdc++.h>
using namespace std;

//#define int long long

void solve() {
	int n, m; cin >> n >> m;
	cout << "SCAN 1 1" << endl;
	int sum; cin >> sum; sum += 4; // r1 + r2 + c1 + c2
	cout << "SCAN " << n << " 1" << endl;
	int sum2; cin >> sum2; sum2 -= 2*n; sum2 += 2; // c1 + c2 - r1 - r2

	int sumc = (sum+sum2)/2;
	int sumr = sum - sumc;
	//cout << "SUM\n" << sumc << ' ' << sumr << '\n'; 

	int maxr = 0;
	for (int r1 = 1; r1 <= n; r1++) {
		int r2 = sumr - r1;
		if (r1 <= r2 && r1 <= n && r2 <= n) {
			maxr = r1;
		}
	}
	cout << "SCAN " << maxr << " 1" << endl;
	int diff; cin >> diff; diff += 2; // max(r1) - r1 + r2 - max(r1) + c1 + c2
	diff -= sumc; 
	// sumr = r1+r2
	// diff = r2-r1
	int r2 = (sumr + diff)/2;
	int r1 = sumr - r2;

	int maxc = 0;
	for (int c1 = 1; c1 <= m; c1++) {
		int c2 = sumc - c1;
		if (c1 <= c2 && c1 <= m && c2 <= m) {
			maxc = c1;
		}
	}
	cout << "SCAN 1 " << maxc << endl;
	cin >> diff; diff += 2; // max(c1) - c1 + c2 - max(c1) + r1 + r2
	diff -= sumr;
	// sumc = c1+c2
	// diff = c2-c1
	int c2 = (sumc + diff)/2;
	int c1 = sumc - c2;

	// (r1 c1) (r2 c2) or (r1 c2) (r2 c1)
	cout << "DIG " << r1 << ' ' << c1 << endl;
	int ok; cin >> ok;

	if (ok) {
		cout << "DIG " << r2 << ' ' << c2 << endl;
		cin >> ok; return;
	} else {
		cout << "DIG " << r2 << ' ' << c1 << endl;
		cin >> ok;
		cout << "DIG " << r1 << ' ' << c2 << endl;
		cin >> ok; return;
	}
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}