#include <bits/stdc++.h>
using namespace std;

#define int long long

int lcm(int a, int b) {
	return a/__gcd(a, b)*b;
}

void solve() {
	int n; cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end(), greater<int>());
	int x, a, y, b; cin >> x >> a >> y >> b;
	if (x < y) {
		swap(a, b);
		swap(x, y);
	}



	// x contributes greater
	int both = lcm(a, b);
	int k; cin >> k;

	int lo = 1, hi = n;
	while (lo < hi) {
		int mid = (lo + hi)/2;
		// can sell this much tickets

		int bt = mid/both;
		int ta = mid/a - bt;
		int tb = mid/b - bt;

		int contrib = 0, petr = 0;
		while (bt--) {
			contrib += (p[petr]*(x+y))/100;
			petr++;
		}
		while (ta--) {
			contrib += (p[petr]*x)/100;
			petr++;
		}
		while (tb--) {
			contrib += (p[petr]*y)/100;
			petr++;
		}

		if (contrib >= k) {
			hi = mid;
		} else {
			lo = mid+1;
		}
	}

	int bt = lo/both;
	int ta = lo/a - bt;
	int tb = lo/b - bt;

	int contrib = 0, petr = 0;
	while (bt--) {
		contrib += (p[petr]*(x+y))/100;
		petr++;
	}
	while (ta--) {
		contrib += (p[petr]*x)/100;
		petr++;
	}
	while (tb--) {
		contrib += (p[petr]*y)/100;
		petr++;
	}

	if (contrib >= k) {
		cout << lo << '\n';
	} else {
		cout << "-1\n";
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}