#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp[2];
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		++mp[i&1][a[i]];
	}
	sort(a.begin(), a.end());
	for (int i=0; i<n; ++i)
		--mp[i&1][a[i]];
	for (int i=0; i<2; ++i)
		for (auto& x : mp[i])
			if (x.second) {
				cout << "NO\n";
				return;
			}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}