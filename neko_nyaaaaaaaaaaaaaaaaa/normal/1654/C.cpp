#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, sum = 0; cin >> n;
	multiset<int> a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; sum += x;
		a.insert(x);
	}

	vector<int> p;
	p.push_back(sum);

	while (1) {
		if (a.empty()) {
			cout << "Yes\n";
			return;
		}

		int mx = *a.rbegin();
		if (mx > *max_element(p.begin(), p.end())) {
			cout << "No\n";
			return;
		}

		// assemble cake
		vector<int> nxt;
		for (int i: p) {
			if (a.find(i) != a.end()) {
				a.erase(a.find(i));
			} else {
				nxt.push_back(i/2);
				nxt.push_back((i+1)/2);
			}
		}
		swap(p, nxt);
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