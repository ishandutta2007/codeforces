#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, k; cin >> n >> k;
	vector<int> s(k);
	for (int i = 0; i < k; i++) {
		cin >> s[i];
	}

	if (k == 1) {
		cout << "Yes\n";
		return;
	}

	vector<int> cz;
	for (int i = 1; i < k; i++) {
		cz.push_back(s[i] - s[i-1]);
	}

	vector<int> cs = cz;
	sort(cs.begin(), cs.end());
	if (cs != cz) {
		cout << "No\n";
		return;
	}

	// all elements no larger than cz[0], sum = s[0]
	int lf = n-k+1;
	int mxSum = cz[0]*lf;
	int needSum = s[0];

	//for (int i: cz) cout << i << ' ';
	//	cout << '\n';

	if (mxSum < needSum) {
		cout << "No\n";
		return;
	} else {
		cout << "Yes\n";
		return;
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