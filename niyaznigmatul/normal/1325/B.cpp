/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	a.resize((int) (unique(a.begin(), a.end()) - a.begin()));
	cout << a.size() << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();	
}