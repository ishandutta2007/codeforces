#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n; cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		++m[a];
	}
	for (auto x : m) if (x.second > 1) {cout << "YES\n"; return;}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}