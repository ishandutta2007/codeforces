#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	map<int, int> a;
	while (n--) {
		int i; cin >> i;
		a[i]++;
	}
	
	vector<int> e;
	for (auto it = a.begin(); it != a.end(); it++) {
		if (it->second >= 2) e.push_back(it->first);
		if (it->second >= 4) {
			int i = it->first;
			cout << i << " " << i << " " << i << " " << i << '\n';
			return;
		}
	}
	
	sort(e.begin(), e.end());
	long double ans = 1e18;
	int a1, a2;
	for (int i = 1; i < e.size(); i++) {
		if (((e[i] + e[i-1])*2*(e[i] + e[i-1])*2.0)/(e[i]*e[i-1]) < ans) {
			ans = ((e[i] + e[i-1])*2.0*(e[i] + e[i-1])*2)/(e[i]*e[i-1]);
			a1 = e[i]; a2 = e[i-1];
		}
	}
	cout << a1 << " " << a1 << " " << a2 << " " << a2 << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}