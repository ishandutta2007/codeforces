#include <bits/stdc++.h>
using namespace std;

vector<int> remov(vector<int> a, int val) {
	vector<int> ans;
	for (int i: a) {
		if (i != val) ans.push_back(i);
	}
	return ans;
} 

bool is_pal(vector<int> a) {
	vector<int> b = a;
	reverse(b.begin(), b.end());
	return a == b;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0, j = n-1; i < j; i++, j--) {
		if (a[i] == a[j]) {
			continue;
		} else {
			if (is_pal(remov(a, a[i])) || is_pal(remov(a, a[j]))) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
			return;
		}
	}
	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}